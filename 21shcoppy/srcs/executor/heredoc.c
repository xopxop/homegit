/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 22:17:58 by dthan             #+#    #+#             */
/*   Updated: 2020/04/28 22:17:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char    *prompt_heredoc(char *end_word)
{
    char *line;

    ft_putstr("heredoc> ");
    if (get_next_line(STDOUT_FILENO, &line) <= 0)
        return (NULL); //it should be return an error here
    if (ft_strequ(line, end_word))
        return (NULL);
    else
    {
        line = ft_strjoin_and_free_string1(line, "\n");
		line = ft_strjoin_and_free_string2(line, prompt_heredoc(end_word));
    }
    return (line);
}

void push_node_into_lheredoc(t_heredoc *node, t_heredoc **head)
{
	t_heredoc *p;

	if (*head == NULL)
		*head = node;
	else
	{
		p = *head;
		while (p->next)
			p = p->next;
		p->next = node;
	}
}

void apply_heredoc(t_astnode *heredoc, t_exe *exe)
{
    t_heredoc *node;

    node = (t_heredoc*)malloc(sizeof(t_heredoc)); 
    node->heredoc = prompt_heredoc(heredoc->data); // if there is next heredoc in one command, should coppy
    node->next = NULL;
    push_node_into_lheredoc(node, &exe->heredoc);
}

void find_heredoc(t_astnode *ast, t_exe *exe)
{
    if (ast->type == AST_io_file && ft_strequ(ast->data, "<<"))
        apply_heredoc(ast->left, exe); // maybe need to change
    else if (ast->type == AST_complete_command)
        find_heredoc(ast->left, exe);
    else if (ast->type == AST_list)
    {
        find_heredoc(ast->left, exe);
        find_heredoc(ast->right, exe);
    }
    else if (ast->type == AST_pipe_sequence)
    {
        find_heredoc(ast->left, exe);
        find_heredoc(ast->right, exe);
    }
    else if (ast->type == AST_simple_command)
        find_heredoc(ast->right, exe);
    else if (ast->type == AST_cmd_suffix)
        find_heredoc(ast->right, exe);
}
