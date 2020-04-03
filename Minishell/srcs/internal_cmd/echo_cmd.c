/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 02:24:28 by dthan             #+#    #+#             */
/*   Updated: 2020/03/30 02:24:28 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#define Y 1
#define N 0

void	echo_cmd(char **words)
{
	char *p;
	int space;

	p = NULL;
	space = N;
	while (*words)
	{
		if (**words == '~')
		{
			if (*(*words + 1) == '\0')
				p = ft_call_value_of("HOME");
		}
		else if (*words[0] == '$' && (p = ft_call_value_of(*words)))
			p += ft_strlen(*words);
		else
			p = *words;
		if (p != NULL)
			space = (ft_printf("%*s", ft_strlen(p) + space, p)) ? Y : N;
		words++;
	}
	ft_putchar('\n');
}
