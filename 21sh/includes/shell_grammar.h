/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_grammar.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 07:06:11 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 07:06:14 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_GRAMMAR_H
# define SHELL_GRAMMAR_H
# include "struct.h"

typedef struct				s_cmd_word
{
	char					*data;
	int						pos;
}							t_cmd_word;

typedef struct				s_cmd_name
{
	t_cmd_word				*cmd_word;
}							t_cmd_name;

typedef struct				s_cmd_suffix
{
	t_cmd_word				*cmd_word;
	struct s_cmd_suffix		*next;
}							t_cmd_suffix;

typedef struct				s_simple_cmd
{
	t_cmd_name				*cmd_name;
	t_cmd_suffix			*cmd_suffix;
	struct s_simple_cmd		*next;
}							t_simple_cmd;

typedef struct				s_pipe_sequence
{
	t_simple_cmd			*simple_cmd;
}							t_pipe_sequence;

typedef struct				s_ast
{
	t_type					type;
	char*					data;
	struct s_ast			*left;
	struct s_ast			*right;
}							t_ast;

typedef enum				e_ast_type
{
	AST_COMMAND,
	AST_SIMPLECOMMAND,
	AST_CMDNAME,
	AST_CMDSUFFIX,
	AST_WORD,
	AST_PIPE_SEQUENCE,
	AST_IO_REDIRECT,
	AST_IO_FILE,
	AST_FILENAME,
	AST_IO_HERE,
	AST_HERE_END,
	AST_COMPLETE_COMMAND,
	AST_LIST,
}							t_ast_type;

t_pipe_sequence				*pipe_sequence(t_token *token);
t_simple_cmd				*simple_cmd(t_token *token);
t_cmd_suffix 				*cmd_suffix(t_token *token);
t_cmd_name					*cmd_name(t_token *token);
t_cmd_word					*cmd_word(t_token *token);

#endif
