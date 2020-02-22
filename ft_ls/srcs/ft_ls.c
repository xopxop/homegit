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

void ft_ls(char **input)
{
    int options;
    // First we pare the input, i means checking the flag
    options = parse_input(input);
    // 
    print_input();
}

int main(int argc, char **argv)
{
    void ft_ls(argv);    
    return (0);
}

/*
int main(int argc, char **argv)
{
    DIR *dir;
    struct dirent *sd;

    dir = opendir(".");
    if (dir == NULL)
    {
        ft_printf("Error! Unable to open directory.\n");
        exit(1);
    }
    while ((sd=readdir(dir)) != NULL)
        ft_printf(">> %s\n", sd->d_name);
    closedir(dir);
    return (0);
}
*/
