/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:25:39 by dthan             #+#    #+#             */
/*   Updated: 2020/08/12 16:42:15 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_vector.h"

void	vector_push_value_int(t_vector_int **vector, int data)
{
	t_vector_int *p;
	t_vector_int *new;
	int i;

	if (vector == NULL || *vector == NULL)
		return ;
	p = *vector;
	i = -1;
	if ((new = vector_create_int_with_size((**vector).array_len + 1)) == NULL)
		return ;
	while (++i < (**vector).array_len)
		new->array[i] = (**vector).array[i];
	new->array[i] = data;
	*vector = new;
	vector_delete_int(p);
}

void	vector_push_value_char(t_vector_char **vector, char data)
{
	t_vector_char *p;
	t_vector_char *new;
	int i;

	if (vector == NULL || *vector == NULL)
		return ;
	p = *vector;
	i = -1;
	if ((new = vector_create_char_with_size((**vector).array_len + 1)) == NULL)
		return ;
	while (++i < (**vector).array_len)
		new->array[i] = (**vector).array[i];
	new->array[i] = data;
	*vector = new;
	vector_delete_char(p);
}