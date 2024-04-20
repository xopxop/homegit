/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:26:00 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 23:24:17 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t		index;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		dst_ptr[index] = src_ptr[index];
		if (dst_ptr[index] == (unsigned char)c)
			return &dst_ptr[index + 1];
		index++;
	}
	return (NULL);
}
