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

typedef struct  s_map
{
    int         x;
    int         y;
    int         z;
}               t_map;

#endif