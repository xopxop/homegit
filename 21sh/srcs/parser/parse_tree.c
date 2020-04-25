/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:28:20 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 15:28:21 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd_word	*cmd_word(t_token *token)
{
	t_cmd_word *w;

	if (token->type == T_WORD)
	{
		w = (t_cmd_word*)malloc(sizeof(t_cmd_word));
		w->data = token->data;
		w->pos = token->pos_args;
		token = token->next;
		return (w);
	}
	return (NULL);
}

t_cmd_name	*cmd_name(t_token *token)
{
	t_cmd_name *cn;
	t_cmd_word *w;

	cn = (t_cmd_name*)malloc(sizeof(t_cmd_name));
	if((w = cmd_word(token)))
	{
		cn->cmd_word = w;
		return (cn);
	}
	free(cn);
	return (NULL);
}

t_cmd_suffix *cmd_suffix(t_token **token)
{
	t_cmd_suffix	*sf;
	t_cmd_word		*w;

	sf = (t_cmd_suffix*)malloc(sizeof(t_cmd_suffix));
	if ((w = cmd_word(token)))
	{
		sf->cmd_word = w;
		return (sf);
	}
	free(sf);
	return (NULL);
}

t_simple_cmd	*simple_cmd(t_token **token)
{
	t_simple_cmd 	*sc;
	t_cmd_name		*cn;
	t_cmd_suffix	*cs;

	sc = (t_simple_cmd*)malloc(sizeof(t_simple_cmd));
	if ((cn = cmd_name(token)))
	{
		sc->cmd_name = cn;
		while((cs = cmd_suffix(token)))
		{
			ft_lstpush_cm_suffix(cs, &sc->cmd_suffix);
		}
		return (sc);
	}
	free(sc);
	return (NULL);
}

t_pipe_sequence	*pipe_sequence(t_token **token)
{
	t_pipe_sequence *ps;
	t_simple_cmd	*sc;

	ps = (t_pipe_sequence*)malloc(sizeof(t_pipe_sequence));
	while ((sc = simple_cmd(token)))
	{
		ft_lstpush_simple_cmd(sc, &ps->simple_cmd);
		if (*token->type == T_PIPE)
			*token = *token->next;
	}
	if (ps->simple_cmd)
		return (ps);
	free(ps);
	return (NULL);
}

t_pipe_sequence *buildingast(t_token *token)
{
	t_pipe_sequence *ast;

	ast = pipe_sequence(&token);
	return (ast);
}