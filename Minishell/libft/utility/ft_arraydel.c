/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 06:29:33 by dthan             #+#    #+#             */
/*   Updated: 2020/07/09 17:45:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

void	ft_arraydel(char **string_array)
{
	char *ptr;

	if (string_array)
	{
		while (*string_array)
		{
			ptr = *string_array;
			string_array++;
			free(ptr);
		}
		ptr = *string_array;
		free(ptr);
	}
}
