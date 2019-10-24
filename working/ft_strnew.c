/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:49:36 by dthan             #+#    #+#             */
/*   Updated: 2019/10/24 16:41:50 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;
	size_t i;

	i = 0;
	if (!(s = malloc(size + 1)))
		return (NULL);
	while (i <= size)
		s[i++] = '\0';
	return (s);
}
