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
    char *str;

    str = ft_strnew(12);
    ft_strncpy(str, ctime(&time)+ 4, 12);
    return (str);
}

char *ft_get_file_permission(mode_t mode)
{
    char *str;

    str = ft_strnew(9);
    str[0] = (mode & S_IRUSR) ? 'r' : '-';
    str[1] = (mode & S_IWUSR) ? 'w' : '-';
    str[2] = (mode & S_IXUSR) ? 'x' : '-';
    str[3] = (mode & S_IRGRP) ? 'r' : '-';
    str[4] = (mode & S_IWGRP) ? 'w' : '-';
    str[5] = (mode & S_IXGRP) ? 'x' : '-';
    str[6] = (mode & S_IROTH) ? 'r' : '-';
    str[7] = (mode & S_IWOTH) ? 'w' : '-';
    str[8] = (mode & S_IXOTH) ? 'x' : '-';
    return (str);
}

char ft_get_data_type(mode_t mode)
{
    if (S_ISBLK(mode))
        return ('b');
    else if (S_ISCHR(mode))
        return ('c');
    if (S_ISDIR(mode))
        return ('d');
    else if (S_ISLNK(mode))
        return ('l');
    else if (S_ISFIFO(mode))
        return ('p');
//    else if (S_IFSOCK(mode))
//        return ('s');
//    else if (S_ISBLK(mode))
//        return ('b');
    else
        return ('-');
}

/*

char ft_get_data_type(mode_t mode)
{
    if ((mode & __S_IFMT) == __S_IFDIR)
        return ('d');
    else if ((mode & __S_IFMT) == __S_IFCHR)
        return ('c');
    else if ((mode & __S_IFMT) == __S_IFLNK)
        return ('l');
    else if ((mode & __S_IFMT) == __S_IFIFO)
        return ('p');
    else if ((mode & __S_IFMT) == __S_IFSOCK)
        return ('s');
    else if ((mode & __S_IFMT) == __S_IFBLK)
        return ('b');
    return ('-');
}
*/

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
    file->type = ft_get_data_type(filestat.st_mode);
    file->file_permission = ft_get_file_permission(filestat.st_mode);
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
        ft_printf("%c%s | %u | %s | %s | %d | %s | %s\n", lfile->type, lfile->file_permission, \
        lfile->link, lfile->user_name, lfile->group_name, \
        lfile->size , lfile->time, lfile->name);
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
