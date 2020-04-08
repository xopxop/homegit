/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:17:31 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 11:17:32 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int parser(t_token *token, t_pipe_sequence *ps)
{
	if (!(ps = pipe_sequence(token)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}