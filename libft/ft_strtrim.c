/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:25:48 by dthan             #+#    #+#             */
/*   Updated: 2019/10/30 09:14:30 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *string)
{
	int stringstart;
	int  stringend;

	stringstart = 0;
	stringend = ft_strlen((char*)string);
	if (!string)
		return (NULL);
	while (ft_isspace(string[stringstart]))
		stringstart++;
	while (ft_isspace(string[stringend - 1]))
		stringend--;
	if (stringend < stringstart)
		stringend = stringstart;
	return (ft_strsub(string, stringstart, stringend - stringstart));
}
