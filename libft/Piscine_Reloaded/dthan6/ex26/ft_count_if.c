/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 08:24:47 by dthan             #+#    #+#             */
/*   Updated: 2019/10/16 09:28:55 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int ct;

	ct = 0;
	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) == 1)
			ct++;
		i++;
	}
	return (ct);
}
