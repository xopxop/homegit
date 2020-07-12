/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 18:43:38 by dthan             #+#    #+#             */
/*   Updated: 2020/07/12 19:08:04 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utility.h"

char	*ft_3strjoin(char const *s1, char const *s2, char const *s3)
{
	char	*jstr;
	size_t	size;

	size = 0;
	size += (s1) ? (size_t)ft_strlen(s1) : 0;
	size += (s2) ? (size_t)ft_strlen(s2) : 0;
	size += (s3) ? (size_t)ft_strlen(s3) : 0;
	if (size == 0)
		return (NULL);
	if (!(jstr = ft_memalloc(size + 1)))
		return (NULL);
	(s1) ? ft_strcat(jstr, s1) : 0;
	(s2) ? ft_strcat(jstr, s2) : 0;
	(s3) ? ft_strcat(jstr, s3) : 0;
	return (jstr);
}
