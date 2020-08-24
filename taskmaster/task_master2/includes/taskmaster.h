/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskmaster.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 10:46:05 by dthan             #+#    #+#             */
/*   Updated: 2020/08/10 08:00:51 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASKMASTER_H
# define TASKMASTER_H
# include "../libft/includes/libft.h"
# include "../iniparser/src/dictionary.h"

typedef struct					s_options
{
	uint64_t					optmask;
	mode_t						umask;
	uint32_t					padding;
	char						*str[8];
	char						*environ;
}								t_options;

typedef struct	s_vector
{
	char		*str;
	size_t		len;
}				t_vector;

typedef struct		s_denv
{
	int				sig_tmp;
	volatile __sig_atomic_t		sigint;
	char						*dfl_socket;
	int32_t						unit_socket;
	int32_t						log_fd;
	t_list						*environ;
	t_list						*prgm_list;
	dictionary					*dict;
	t_options					opt;
	struct sockaddr_un			add;
	uint8_t						client_connected;
	int8_t						lock;
	uint8_t						shutdown;
	char						pad[7];
	char						**environ_tab;
	t_vector					**av;
	int							ac;
	char						padd[4];
}								t_denv;

t_denv	*g_denv;
t_denv	*g_tmpenv;

#endif