/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 21:35:36 by dthan             #+#    #+#             */
/*   Updated: 2020/01/06 21:35:57 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	type_percent(t_info *info, __attribute__((unused)) va_list arg, char **output)
{
	char percent;
	char *str;

	percent = '%';
	str = ft_strnew(1);
	str[0] = percent;
	ft_pad_handle(info, &str);
	*output = str;
}