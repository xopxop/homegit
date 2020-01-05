/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:45:28 by dthan             #+#    #+#             */
/*   Updated: 2020/01/03 15:47:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

typedef struct  s_line
{
    char        *content;
    size_t      content_size;
    struct s_line   *next;
}               t_line;

typedef struct s_map
{
    int         x;
    int         y;
    int         z;
}               t_map;

int read_file(int fd, t_map *map);
int error_handle(char* reason);

#endif