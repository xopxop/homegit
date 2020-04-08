/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 07:58:26 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 07:58:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum			e_type{
	T_WORD,
	T_PIPE,
}						t_type;

typedef struct			s_token
{
	char				*data;
	t_type				type;
	int					pos_args;
	struct s_token		*next;
}						t_token;

typedef struct			s_cmd
{
	t_token				*token;
	char				**argv;
	int					argc;
	struct s_cmd		*next;
}						t_cmd;

typedef struct			s_builtin
{
	char				*command;
	void				(*func)(char**);
}						t_builtin;

#endif
