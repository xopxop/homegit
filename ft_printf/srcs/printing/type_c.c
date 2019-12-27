/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:33:24 by dthan             #+#    #+#             */
/*   Updated: 2019/12/23 04:33:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** ft printing for type_c
** RETURN VALUE: a string for type_c
*/

void type_c(t_info* info , va_list arg, char **output)
{
    char chr;
    char *str;
    
    chr = va_arg(arg, int);
    str = ft_strnew(1);
    str[0] = chr;
    ft_pad_handle(info, &str);
    *output = str;
}
