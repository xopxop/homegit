/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:26:05 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 23:26:39 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	ct;

	ct = 0;
	while ((src[ct]) && (ct < len))
	{
		dst[ct] = src[ct];
		ct++;
	}
	while (ct < len)
	{
		dst[ct] = '\0';
		ct++;
	}
	return (dst);
}
