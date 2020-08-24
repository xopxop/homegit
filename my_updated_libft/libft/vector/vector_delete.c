/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:42:44 by dthan             #+#    #+#             */
/*   Updated: 2020/08/12 16:46:33 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_vector.h"

void	vector_delete_int(t_vector_int *vector)
{
	if (vector->array_len > 0)
		free(vector->array);
	free(vector);
}

void	vector_delete_char(t_vector_char *vector)
{
	if (vector->array_len > 0)
		free(vector->array);
	free(vector);
}