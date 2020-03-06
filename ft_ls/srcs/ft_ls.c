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
    else if (S_ISSOCK(mode))
        return ('s');
    else if (S_ISBLK(mode))
        return ('b');
    else
        return ('-');
}

void initialize_struct(t_file *file)
{
    file->name = NULL;
    file->path = NULL;
    file->user_name = NULL;
    file->group_name = NULL;
    file->link = 0;
    file->size = 0;
    file->time = NULL;
    file->file_permission = NULL;
    file->type = '\0';
    file->is_hidden = NO;
    file->allow_open = YES;
}

void ft_get_file_info(t_file **lfile, char *filename, char *path)
{
    t_file *file;
    t_file *ptr;
    struct stat filestat;

    if (!(file = (t_file*)malloc(sizeof(t_file))))
        ft_err_malloc();
    initialize_struct(file);
    file->name = ft_strdup(filename);
    if (path == NULL)
        file->path = ft_strdup(filename);
    else
        file->path = ft_strjoin_and_free_string1(ft_strjoin(path, "/"), file->name);
    lstat(file->path, &filestat);
    file->type = ft_get_data_type(filestat.st_mode);
    file->file_permission = ft_get_file_permission(filestat.st_mode);
    file->link = filestat.st_nlink;
    file->user_name = ft_get_user_name(filestat.st_uid);
    file->group_name = ft_get_group_name(filestat.st_gid);
    file->size = filestat.st_size;
    file->time = ft_get_time(filestat.st_mtime);
    file->blocks = filestat.st_blocks / 2;
    if (file->name[0] == '.')
        file->is_hidden = YES;
    if (!(ft_strcmp(".", file->name))  || !(ft_strcmp("..", file->name)))
        file->allow_open = NO;
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


void ft_print_long_list(t_file *lfile, int options)
{
    int block_ct;
    t_file *tmp;

    block_ct = 0;
    tmp = lfile;
 //   ft_printf("%s:\n", lfile->path);
    while (tmp)
    {
        if (!(options & LIST_HIDDEN) && tmp->is_hidden == YES)
            tmp = tmp->next;
        else
        {
            block_ct += tmp->blocks;
            tmp = tmp->next;
        }
    }
    ft_printf ("total %d\n", block_ct);
    while (lfile)
    {
        if (!(options & LIST_HIDDEN) && lfile->is_hidden == YES)
            ;
        else
        {
            ft_printf("%c%s | %u | %s | %s | %d | %s | %s\n", lfile->type, lfile->file_permission, \
            lfile->link, lfile->user_name, lfile->group_name, \
            lfile->size , lfile->time, lfile->name);
        }
        lfile = lfile->next;
    }
}

void ft_print_short_list(t_file *lfile, int options)
{
    while (lfile)
    {
        if (!(options & LIST_HIDDEN) && lfile->is_hidden == YES)
            ;
        else
            ft_printf("%s\n", lfile->name);
        lfile = lfile->next;
    }
}

void display(t_file *lfile, int options)
{
    if (options & LONG_LIST_FORMAT)
        ft_print_long_list(lfile, options);
    else
        ft_print_short_list(lfile, options);
}

void free_lfile(t_file *file)
{
    t_file *temp;

    while (file)
    {
        temp = file;
        file = file->next;
        free(temp->name);
        free(temp->path);
        free(temp->user_name);
        free(temp->group_name);
        free(temp->time);
        free(temp->file_permission);
        free(temp);
    }
}

void recusion(t_file **input_file, int options)
{
    DIR *ptr_dir;
    struct dirent *ptr_entry;
    t_file* file;

    file = NULL;
    if(!(ptr_dir = opendir((*input_file)->path)))
        ft_err_permission_dinied((*input_file)->name);
    else
    {
        while ((ptr_entry = readdir(ptr_dir)))
            ft_get_file_info(&file, ptr_entry->d_name, (*input_file)->path);
        closedir(ptr_dir);
        ft_printf("%s:\n", (*input_file)->path);
        display(file, options);
        if (options & LIST_SUBDIR_RECUSIVELY)
            while (file)
            {
                if (file->type == 'd' && file->allow_open == YES)
                {
                    ft_printf("\n");
                    recusion(&file, options);
                }
                else
                    file = file->next;
            }
        free_lfile(file);
    }
    *input_file = (*input_file)->next;
}

void ft_ls(char **input)
{
    int arg_nbr;
    int options;
    t_file *ldir;
    t_file *temp;

    arg_nbr = 1;
    options = 0;
    ldir = NULL;
    while(input[arg_nbr])
    {
        if (ft_isoptions(input[arg_nbr][0]))
            options |= get_options(input[arg_nbr]);
        else if (ft_isdir(input[arg_nbr]))
            ft_get_file_info(&ldir, input[arg_nbr], NULL);
//            get_dir(input[arg_nbr], &ldir);
        arg_nbr++;
    }
    if (ldir == NULL)
        ft_get_file_info(&ldir, ".", ".");
//        get_dir(".", &ldir);
    temp = ldir;
    while(ldir)
        recusion(&ldir, options);
    free_lfile(temp);
}

int main(int ac, char **av)
{
    (void)ac;
    ft_ls(av);
    return (EXIT_SUCCESS);
}
