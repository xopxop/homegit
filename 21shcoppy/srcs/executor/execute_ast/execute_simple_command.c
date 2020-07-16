/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 08:39:32 by dthan             #+#    #+#             */
/*   Updated: 2020/04/16 08:39:35 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void execute_simple_command(t_astnode *ast, t_exe *exe)
{
	if (ast->type == AST_simple_command)
	{
		get_av_cmd_name(ast->left, exe);
		get_av_cmd_suffix(ast->right, exe);
	}
	else
		get_av_cmd_name(ast, exe);
	run(*exe);
	if (ft_strequ(exe->redirect_op, "<<"))
		exe->heredoc =  exe->heredoc->next;
	// reset redirect_op
	exe->redirect_op = (exe->redirect_op) ? NULL : NULL;
	exe->redirect_des = (exe->redirect_des) ? NULL : NULL;
	exe->redirect_src = (exe->redirect_src) ? NULL : NULL;
}
