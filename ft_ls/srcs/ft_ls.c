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

char *ft_get_user_name(uid_t id)
{
    struct passwd *pwd;

    if (!(pwd = getpwuid(id)))
        return (ft_itoa(id));
    return (ft_strdup(pwd->pw_name));
}

char *ft_get_group_name(gid_t id)
{
    struct group *grp;

    if (!(grp = getgrgid(id)))
        return (ft_itoa(id));
    return (ft_strdup(grp->gr_name));
}

char *ft_get_time(time_t time)
{
    
    return (str);
}

void ft_get_file_info(t_file **lfile, char *filename, char *path)
{
    t_file *file;
    t_file *ptr;
    struct stat filestat;

    if (!(file = (t_file*)malloc(sizeof(t_file))))
        ft_err_malloc();
    file->name = ft_strdup(filename);
    file->path = ft_strjoin_and_free_string1(ft_strjoin(path, "/"), file->name);
    stat(file->path, &filestat);
    file->link = filestat.st_nlink;
    file->user_name = ft_get_user_name(filestat.st_uid);
    file->group_name = ft_get_group_name(filestat.st_gid);
    file->size = filestat.st_size;
    file->time = ft_get_time(filestat.st_mtime);
    file->next = NULL;
    if (*lfile == NULL)
        *lfile = file;
    else
    {
        ptr = *lfile;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = file;
    }
}


void ft_print_long_list(t_file *lfile)
{
    while (lfile)
    {
        ft_printf("%u  %s  %s  %d  %s\n", lfile->link, lfile->user_name, lfile->group_name, \
        lfile->size , lfile->name);
        lfile = lfile->next;
    }
}

void display(t_file *lfile, int options)
{
    if (options & LONG_LIST_FORMAT)
        ft_print_long_list(lfile);
    else
    {
        while (lfile)
        {
            ft_printf("%s\n", lfile->name);
            lfile = lfile->next;
        }
    }
}

void free_lfile(t_file *file)
{
    t_file *temp;

    while (file)
    {
        temp = file;
        free(file->name);
        free(file->path);
        free(file->user_name);
        free(file->group_name);
        file = file->next;
        free(temp);
    }
}

void fill_tree(t_dir *lst_dir_input, int options)
{
    DIR *ptr_dir;
    struct dirent *ptr_entry;
    t_file *file;

    while(lst_dir_input)
    {
        file = NULL;
        if(!(ptr_dir = opendir(lst_dir_input->name)))
            ft_err_permission_dinied(lst_dir_input->name);
        while ((ptr_entry = readdir(ptr_dir)))
            ft_get_file_info(&file, ptr_entry->d_name, lst_dir_input->name);
        closedir(ptr_dir);
        display(file, options);
        free_lfile(file);
        lst_dir_input = lst_dir_input->next;
    }
}

void ft_ls(char **input)
{
    int arg_nbr;
    int options;
    t_dir *ldir;

    arg_nbr = 1;
    options = 0;
    ldir = NULL;
    while(input[arg_nbr])
    {
        if (ft_isoptions(input[arg_nbr][0]))
            options |= get_options(input[arg_nbr]);
        else if (ft_isdir(input[arg_nbr]))
            get_dir(input[arg_nbr], &ldir);
        arg_nbr++;
    }
    if (ldir == NULL)
        get_dir(".", &ldir);
    fill_tree(ldir, options);
    t_dir *temp;
    while (ldir)
    {
        temp = ldir;
        ldir = ldir->next;
        free(temp->name);
        free(temp);
    }
}

int main(int ac, char **av)
{
    (void)ac;
    ft_ls(av);
    return (EXIT_SUCCESS);
}
