/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 03:32:04 by dthan             #+#    #+#             */
/*   Updated: 2019/12/07 05:33:40 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

typedef struct	s_flags
{
	int		hash_key;
	int		zero;
	int		minus_sign;
	int		plus_sign;
	int		space;
}			t_flags;

typedef struct		s_width
{
	int		nbr;
	int		asterisk;
}			t_width;

typedef struct		s_percision
{
	int		nbr;
	int		asterisk;
}			t_percision;

typedef struct		s_specifier
{
	int		type_d;
	int		type_i;
	int		type_u;
	int		type_o;
	int		type_x;
	int		type_X;
	int		type_f;
	int		type_c;
	int		type_s;
	int		type_p;
	int		nothing;
	int		percentage_sign;
}			t_specifier;

typedef struct		s_info
{
	t_flags		flags;
	t_width		width;
	t_percision	percision;
	t_specifier	specifier;
}			t_info;

#endif