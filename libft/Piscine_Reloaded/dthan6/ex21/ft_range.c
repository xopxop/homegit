/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:21:13 by dthan             #+#    #+#             */
/*   Updated: 2019/10/15 16:50:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int length;
	int count;

	if (min >= max)
	{
		arr = NULL;
		return (arr);
	}
	else
	{
		length = max - min;
		arr = (int*)malloc(sizeof(*arr) * (length));
		count = 0;
		while (count < length)
		{
			arr[count] = min + count;
			count++;
		}
		return (arr);
	}
}
