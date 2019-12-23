/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:47:36 by dthan             #+#    #+#             */
/*   Updated: 2019/12/07 18:00:01 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** inilializing the struc info
*/

void struct_init(t_info *info)
{
    info->flags = 0;
	info->field_width = -1;
	info->percision = -1;
	info->length = '\0';
    info->specifier = '\0';
}

/*
** ft_skip_atoi will take the number from the string
** Return value: the number from the str
*/

int ft_skip_atoi(const char *format, size_t *pos)
{
    int i = 0;

    while (ft_isdigit(format[*pos]))
        i = i * 10 + format[(*pos)++] - '0';
    return (i);
}

