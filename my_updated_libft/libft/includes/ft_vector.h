/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 09:57:10 by dthan             #+#    #+#             */
/*   Updated: 2020/08/12 16:46:47 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H
# include "ft_string.h"
# include "ft_stdlib.h"
# include "ft_stdbool.h"

/*
**	simple dynamic array
**	void *array: void pointer points to the array
**	size_t elem_size: size of the element in the array
**	size_t array_len: length of the array
**	size_t storage: current capacity of the array
*/

typedef struct		s_vector_int
{
	int				*array;
	size_t			array_len;
}					t_vector_int;

typedef struct		s_vector_char
{
	char			*array;
	size_t			array_len;
}					t_vector_char;

/*
**	create array
*/

t_vector_int *vector_create_int(void);
t_vector_char *vector_create_char(void);
t_vector_int *vector_create_int_with_size(size_t array_len);
t_vector_char *vector_create_char_with_size(size_t array_len);

/*
**	delete array
*/

void	vector_delete_int(t_vector_int *vector);
void	vector_delete_char(t_vector_char *vector);

/*
**	push array
*/

void	vector_push_value_int(t_vector_int **vector, int data);
void	vector_push_value_char(t_vector_char **vector, char data);

#endif
