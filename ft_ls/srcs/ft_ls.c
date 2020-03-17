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

void ft_get_file_info(t_node **lnode, char *filename, char *path)
{
    t_node *node;
    t_node *ptr;
    struct stat filestat;

    if (!(node = (t_node*)malloc(sizeof(t_node))))
        ft_err_malloc();
    initialize_struct(node);
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
    if (node->status.name[0] == '.')
        node->status.is_hidden = YES;
    if (!(ft_strcmp(".", node->status.name))  || !(ft_strcmp("..", node->status.name)))
        node->status.allow_open = NO;
    node->next = NULL;
    if (*lnode == NULL)
        *lnode = node;
    else
    {
        ptr = *lnode;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = node;
    }
}

void recusion(t_node *parent, int options)
{
    DIR *ptr_dir;
    struct dirent *ptr_entry;
    t_node* child;

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
                    ft_get_file_info(&child, ptr_entry->d_name, parent->status.path);
                closedir(ptr_dir);
                display(child, options);
                recusion(child, options);
                free_lfile(child);
            }
        }
        parent = parent->next;
    }
}

int ft_ls(t_node *parent, int options)
{
    t_node *child;
    DIR *ptr_dir;
    struct dirent *ptr_entry;

    child = NULL;
    while(parent)
    {
        if(!(ptr_dir = opendir(parent->status.path)))
            display(parent, options);
        else
        {
            while ((ptr_entry = readdir(ptr_dir)))
                ft_get_file_info(&child, ptr_entry->d_name, parent->status.path);
            closedir(ptr_dir);
            ft_sort(child, options);
            display(child, options);
            if (options & LIST_SUBDIR_RECUSIVELY)
                recusion(child, options);
            free_lfile(child);
        }
        parent = parent->next;
    }
    return (0); // change later
}

int get_arguments(char **input, int *options, t_node **lst)
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
            ft_get_file_info(lst, input[arg_nbr], NULL);
        arg_nbr++;
    }
    if (*lst == NULL)
        ft_get_file_info(lst, ".", NULL);
    return (ret);
}

int main(int ac, char **av)
{
    int options;
    t_node *lst;
    int ret;

    ret = 0;
    options = 0;
    lst = NULL;
    (void)ac;
    ret = get_arguments(av, &options, &lst);
    ret = ft_ls(lst, options);
    free_lfile(lst);
    if (ret == 1)
        return (MINOR_PROBLEMS);
    return (EXIT_SUCCESS);
}
