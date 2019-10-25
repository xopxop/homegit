/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:41:15 by dthan             #+#    #+#             */
/*   Updated: 2019/10/23 14:47:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *string, int fileDescriptor)
{
	ft_putstr_fd(string, fileDescriptor);
	ft_putchar_fd('\n', fileDescriptor);
}
