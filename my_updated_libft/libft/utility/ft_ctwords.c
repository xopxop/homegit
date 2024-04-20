/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:23:18 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 14:15:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_ctwords(char const *str, char c)
{
	size_t	count;
	int		is_inside;

	is_inside = 0;
	count = 0;
	while (*str)
	{
		if (!is_inside && *str != c)
			count++;
		if (*str == c)
			is_inside = 0;
		else
			is_inside = 1;
		str++;
	}
	return (count);
}
