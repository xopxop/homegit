/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:29:33 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 14:15:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_arraydel(char **string_array)
{
	int	index;

	index = 0;
	if (string_array)
	{
		while (string_array[index])
		{
			free(string_array[index]);
			string_array[index] = NULL;
			index++;
		}
		free(string_array);
	}
}
