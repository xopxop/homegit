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
# define ISFLAG 1
# define IS_NOT_FLAG 0

int get_options(char *input, int *options)
{
    input++;
    while(*input)
    {
        if (*input++ == 'l')
            *options |= LONG_LIST_FORMAT; 
        else if (*input++ == 'R')
            *options |= LIST_SUBDIR_RECUSIVELY;
        else if (*input++ == 'a')
            *options |= LIST_HIDDEN;
        else if (*input++ == 'r')
            *options |= REVERSE_ORDER;
        else if (*input++ == 't')
            *options |= SORT_BY_NEWEST_FIRST;
        else
            return(SERIOUS_TROUBLE);
    }
    return (OK);
}

int get_dir(char *input, t_dinfo **ldir)
{
    DIR *current_dir;
    t_dinfo *new;

    if (!(new = (t_dinfo*)ft_memalloc(sizeof(t_dinfo))))
        return (MINOR_PROBLEMS);
    new->dir_name = ft_strdup(input);
    current_dir = opendir(new->dir_name);
    if (current_dir == NULL)
        return (MINOR_PROBLEMS);
    closedir(current_dir);
    new->next = NULL;
    if (!*ldir)
        *ldir = new;
    else
        (*ldir)->next = new;
    return (OK);
}

void output(/*int options, */t_dinfo *dir)
{
    DIR *current_dir;
    struct dirent *entry;
    struct stat filestat;

    while(dir != NULL)
    {
        current_dir = opendir(dir->dir_name);
        ft_printf("open return%d\n", opendir(dir->dir_name));
        while ((entry = readdir(current_dir)))
        {
            //Test
            ft_printf("%s\nstat return: %d\n", entry->d_name, stat(entry->d_name, &filestat));
            ft_printf("with octal number %s : %o\n", entry->d_name, filestat.st_mode);
            ft_printf("----------");
            // if (S_ISDIR(filestat.st_mode))
            //     ft_printf("%s: %s\n", "DIR", entry->d_name);
            // else
            //     ft_printf("%s: %s\n", "FILE", entry->d_name);
        }
        closedir(current_dir);
        dir = dir->next;
    }
}

int ft_ls(char **input)
{
    int arg_nbr;
    int options;
    int exit_status;
    t_dinfo *ldir;

    arg_nbr = 1;
    ldir = NULL;
    while(input[arg_nbr])
    {
        if (input[arg_nbr][0] == '-')
            exit_status = get_options(input[arg_nbr], &options);
        else
            exit_status = get_dir(input[arg_nbr], &ldir);
        if (exit_status == MINOR_PROBLEMS || exit_status == SERIOUS_TROUBLE)
            return (exit_status);
        arg_nbr++;
    }
    output(/*options, */ ldir);
    return (OK);
}

int main(int ac, char **av)
{
    // test ac
    if (ac > -3)
        return (ft_ls(av));
    return (0);
}
