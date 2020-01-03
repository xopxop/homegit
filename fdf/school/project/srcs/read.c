/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:49:43 by dthan             #+#    #+#             */
/*   Updated: 2020/01/03 16:49:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int get_line()
{
    int ret;
    char *line;

    while(ret = get_next_line(fd, &line))
    {

    }
    return (1);
}

int read_file(int fd, t_map *map)
{
    get_line();
    get_map();
    
}