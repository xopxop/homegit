/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:34:28 by dthan             #+#    #+#             */
/*   Updated: 2019/12/31 14:29:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** This function is for printing type string
** geting the string, taking care of the precison and padding
*/

void	type_s(t_info *info, va_list arg, size_t *ct)
{
	char *ctemp;
	char *str;

	ctemp = va_arg(arg, char*);
	if (!ctemp)
		str = ft_strdup("(null)");
	else
	{
		str = ft_strdup(ctemp);
		ft_prec_handle(info, &str);
		ft_pad_handle(info, &str);
	}
	write(STDOUT, str, *ct = ft_strlen(str));
	free(str);
}
