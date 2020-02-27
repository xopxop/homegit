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

/*
** To do: Learn about binary tree
** I think it can be the way to deal with a directory with 2 types file
** 1 is directory and 2 is a file, so i can create a path to go to the subdirectory
*/

void output(/*int options, */t_dinfo *dir)
{
    DIR *current_dir;
    struct dirent *entry;
    struct stat filestat;

    while(dir != NULL)
    {
        current_dir = opendir(dir->dir_name);
        while ((entry = readdir(current_dir)))
        {
            stat(entry->d_name, &filestat);
            //Test
            ft_printf("name: %s\n", entry->d_name);
            //ft_printf("with octal number %s : %o\n", entry->d_name, filestat.st_mode);
            //ft_printf("----------");
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
