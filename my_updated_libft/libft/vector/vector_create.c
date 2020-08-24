/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:47:50 by dthan             #+#    #+#             */
/*   Updated: 2020/08/12 16:30:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_vector.h"

t_vector_int *vector_create_int(void)
{
	t_vector_int *new;

	if ((new = (t_vector_int*)ft_memalloc(sizeof(t_vector_int))) == NULL)
		return (NULL);
	new->array = 0;
	new->array_len = 0;
	return (new);
}

t_vector_char *vector_create_char(void)
{
	t_vector_char *new;

	if ((new = (t_vector_char*)ft_memalloc(sizeof(t_vector_char))) == NULL)
		return (NULL);
	new->array = NULL;
	new->array_len = 0;
	return (new);
}

t_vector_int *vector_create_int_with_size(size_t array_len)
{
	t_vector_int *new;

	new = vector_create_int();
	if (array_len == 0)
		return (new);
	if ((new->array = (int*)ft_memalloc(sizeof(int) + 1)) == NULL)
	{
		free(new);
		return (NULL);
	}
	new->array_len = array_len;
	ft_bzero(new->array, new->array_len);
}

t_vector_char *vector_create_char_with_size(size_t array_len)
{
	t_vector_char *new;

	new = vector_create_char();
	if (array_len == 0)
		return (new);
	if ((new->array = (char*)ft_memalloc(sizeof(char) + 1)) == NULL)
	{
		free(new);
		return (NULL);
	}
	new->array_len = array_len;
	ft_bzero(new->array, new->array_len);
}
