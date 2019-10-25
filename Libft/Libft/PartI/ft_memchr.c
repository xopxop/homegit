/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:09:19 by dthan             #+#    #+#             */
/*   Updated: 2019/10/19 19:27:20 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr;
	int i;

	ptr = (unsigned char*)s;
	i = 0;
	while(n--)
	{
		if (ptr[i] == c)
			return((void*)(s + i));
		else
			i++;
	}
	return (NULL);
}
