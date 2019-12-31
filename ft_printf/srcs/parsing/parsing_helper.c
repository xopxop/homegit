/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:52:04 by dthan             #+#    #+#             */
/*   Updated: 2019/12/31 14:52:08 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_skip_atoi will take the number from the string
** Return value: the number from the str
*/

int	ft_skip_atoi(const char *format, size_t *pos)
{
	int i = 0;

	while (ft_isdigit(format[*pos]))
		i = i * 10 + format[(*pos)++] - '0';
	return (i);
}
