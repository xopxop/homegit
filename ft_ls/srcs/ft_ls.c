/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 05:33:01 by dthan             #+#    #+#             */
/*   Updated: 2020/02/21 05:33:03 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void initialize_struct(t_node *node)
{
    node->status.name = NULL;
    node->status.path = NULL;
    node->status.user_name = NULL;
    node->status.group_name = NULL;
    node->status.link = 0;
    node->status.size = 0;
    node->status.time = NULL;
    node->status.file_permission = NULL;
    node->status.type = '\0';
    node->status.is_hidden = NO;
    node->status.allow_open = YES;
}

int ft_numlen(int num)
{
    int ct;

    ct = 0;
    if (num < 0)
    {
        ct++;
        num *= -1;
    }
    while (num > 9)
    {
        num /= 10;
        ct++;
    }
    return (ct + 1);
}

t_min ft_get_min(t_node *node)
{
    t_min min;

    min.width_of_link = ft_numlen(node->status.link); // not using itoa, memory leak
    min.width_of_user_name = ft_strlen(node->status.user_name);
    min.width_of_group_name = ft_strlen(node->status.group_name);
    min.width_of_size = ft_numlen(node->status.size); //need to change later
    return (min);
}

void ft_get_file_info(t_node *node, char *filename, char *path)
{
//    t_node *node;
//    t_node *ptr;
    struct stat filestat;

//    if (!(node = (t_node*)malloc(sizeof(t_node))))
//        ft_err_malloc();
//    initialize_struct(node);
    node->status.name = ft_strdup(filename);
    if (path == NULL)
        node->status.path = ft_strdup(filename);
    else
        node->status.path = ft_strjoin_and_free_string1(ft_strjoin(path, "/"), node->status.name);
    lstat(node->status.path, &filestat);
    node->status.type = ft_get_data_type(filestat.st_mode);
    node->status.file_permission = ft_get_file_permission(filestat.st_mode);
    node->status.link = filestat.st_nlink;
    node->status.user_name = ft_get_user_name(filestat.st_uid);
    node->status.group_name = ft_get_group_name(filestat.st_gid);
    node->status.size = filestat.st_size;
    node->status.time = ft_get_time(filestat.st_mtime);
    node->status.blocks = filestat.st_blocks / 2;
    node->status.stats = filestat;
    node->status.min_of = ft_get_min(node);
    if (node->status.name[0] == '.')
        node->status.is_hidden = YES;
    if (!(ft_strcmp(".", node->status.name))  || !(ft_strcmp("..", node->status.name)))
        node->status.allow_open = NO;
    node->next = NULL;
//    if (*lnode == NULL)
//        *lnode = node;
//    else
//    {
//        ptr = *lnode;
//        while (ptr->next)
//            ptr = ptr->next;
//        ptr->next = node;
//    }
}

void ft_push_node_to_lst(t_node **head, t_node *node)
{
    t_node *ptr;

    if (*head == NULL)
        *head = node;
    else
    {
        ptr = *head;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = node;
    }
    
}

void recusion(t_node *parent, int options)
{
    DIR *ptr_dir;
    struct dirent *ptr_entry;
    t_node* child;
    t_node* node;

    while (parent)
    {
        if (parent->status.type == 'd' && parent->status.allow_open == YES)
        {
            write(1, "\n", 1);
            if(!(ptr_dir = opendir(parent->status.path)))
                ft_err_permission_dinied(parent->status.name);
            else
            {
                child = NULL;
                while ((ptr_entry = readdir(ptr_dir)))
                {
                    if (!(node = (t_node*)malloc(sizeof(t_node))))
                        ft_err_malloc();
                    initialize_struct(node);
                    ft_get_file_info(node, ptr_entry->d_name, parent->status.path);
                    ft_push_node_to_lst(&child, node);
                }
                closedir(ptr_dir);
                ft_sort(child, options);
                display(parent ,child, options);
                recusion(child, options);
                free_lfile(child);
            }
        }
        parent = parent->next;
    }
}

int ft_ls(t_args parent, int options)
{
    t_node *child;
    t_node *node;
    DIR *ptr_dir;
    struct dirent *ptr_entry;

    while (parent.file)
    {
        display(parent.file, NULL, options);
        parent.file = parent.file->next;
    }
    while(parent.dir)
    {
        child = NULL;
        ptr_dir = opendir(parent.dir->status.path);
        while ((ptr_entry = readdir(ptr_dir)))
        {
            if (!(node = (t_node*)malloc(sizeof(t_node))))
                ft_err_malloc();
            initialize_struct(node);
            ft_get_file_info(node, ptr_entry->d_name, parent.dir->status.path);
            ft_push_node_to_lst(&child, node);
        }
        closedir(ptr_dir);
        ft_sort(child, options);
        display(parent.dir, child, options);
        if (options & LIST_SUBDIR_RECUSIVELY)
            recusion(child, options);
        free_lfile(child);
        parent.dir = parent.dir->next;
    }
    return (0); // change later
}


void ft_split_input(char *name ,t_args *lst)
{
    t_node *node;

    if (!(node = (t_node*)malloc(sizeof(t_node))))
        ft_err_malloc();
    initialize_struct(node);
    ft_get_file_info(node, name, NULL);
    if (node->status.type == 'd')
        ft_push_node_to_lst(&lst->dir, node);
    else
        ft_push_node_to_lst(&lst->file, node);
}

int get_arguments(char **input, int *options, t_args *lst)
{
    int ret;
    int arg_nbr;

    ret = 0;
    arg_nbr = 1;
    while(input[arg_nbr])
    {
        if (ft_isoptions(input[arg_nbr][0]))
            *options |= get_options(input[arg_nbr]);
        else if (ft_isfile(input[arg_nbr], &ret))
            ft_split_input(input[arg_nbr], lst);
        arg_nbr++;
    }
    if (lst->dir == NULL && lst->file == NULL)
        ft_split_input(".", lst);
    return (ret);
}

void ft_free_larg(t_args *input_file)
{
    if (input_file->file != NULL)
        free_lfile(input_file->file);
    if (input_file->dir != NULL)
        free_lfile(input_file->dir);
}

int main(int ac, char **av)
{
    int options;
    t_args input_file;
    int ret;

    ret = 0;
    options = 0;
    input_file.file = NULL;
    input_file.dir = NULL;
    (void)ac;
    ret = get_arguments(av, &options, &input_file);
    ret = ft_ls(input_file, options);
    ft_free_larg(&input_file); //need to fix
    if (ret == 1)
        return (MINOR_PROBLEMS);
    return (EXIT_SUCCESS);
}
