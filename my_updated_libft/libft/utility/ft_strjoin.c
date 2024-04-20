/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:55:44 by dthan             #+#    #+#             */
/*   Updated: 2024/04/20 23:30:41 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string/ft_string.h"
#include "ft_utility.h"

static void copy_data(char *str, char const *str_one, char const *str_two)
{
	if (str_one && !str_two)
		ft_strcpy(str, (char *)str_one);
	else if (str_two && !str_one)
		ft_strcpy(str, (char *)str_two);
	else if (str_one && str_two)
	{
		ft_strcpy(str, (char *)str_one);
		ft_strcat(str, (char *)str_two);
	}
}

char	*ft_strjoin(char const *str_one, char const *str_two)
{
	char	*str;
	size_t	str_size;

	if (str_one && str_two)
		str_size = (size_t)(ft_strlen(str_one) + ft_strlen(str_two));
	else if (str_one)
		str_size = (size_t)(ft_strlen(str_one));
	else if (str_two)
		str_size = (size_t)(ft_strlen(str_two));
	else
		return (NULL);
	str = ft_memalloc(str_size + 1);
	if (!str)
		return (NULL);
	copy_data(str, str_one, str_two);
	return (str);
}
