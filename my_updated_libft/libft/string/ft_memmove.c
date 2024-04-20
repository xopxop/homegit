/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:17:42 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 23:25:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	if (ps < pd)
	{
		pd += len;
		ps += len;
		while (len--)
			*--pd = *--ps;
	}
	else
		while (len--)
			*pd++ = *ps++;
	return (dst);
}
