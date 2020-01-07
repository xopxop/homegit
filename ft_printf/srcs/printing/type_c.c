/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:33:24 by dthan             #+#    #+#             */
/*   Updated: 2019/12/31 14:15:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** ft printing for type_c
** Taking the argument, put into a string and padding (if)
*/

void	type_c(t_info* info , va_list arg, size_t *ct)
{
	char chr;
	char *str;
    int null;

	chr = va_arg(arg, int);
	str = ft_strnew(1);
    null = (chr == '\0') ? 1 : 0;
	str[0] = chr;
	ft_pad_handle(info, &str);
	if (null)
	{
        if (info->field_width < 2)
			*ct = 1;
		else
			*ct = ft_strlen(str);
	}
	write(STDOUT, str, ft_strlen(str));
	free(str);
}
