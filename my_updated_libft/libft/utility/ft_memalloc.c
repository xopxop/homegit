/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:48:19 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 23:29:55 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../string/ft_string.h"

void	*ft_memalloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, size);
	return (pointer);
}
