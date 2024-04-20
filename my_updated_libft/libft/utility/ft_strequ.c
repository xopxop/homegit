/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:42:08 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 23:30:10 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"

int	ft_strequ(char const *str_one, char const *str_two)
{
	if (!str_one || !str_two)
		return (0);
	if (ft_strcmp(str_one, str_two))
		return (0);
	return (1);
}
