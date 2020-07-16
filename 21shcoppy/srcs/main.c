/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 09:18:23 by dthan             #+#    #+#             */
/*   Updated: 2020/07/16 04:02:03 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_promt(void)
{
	char *ptr_dir;
	char *promt;

	promt = ft_strdup("minishell:");
	ptr_dir = ft_strrchr(ft_call_value_of("PWD"), '/') + 1;
	if (*ptr_dir == '\0')
		promt = ft_strjoin_and_free_string1(promt, "/");
	else if (!ft_strcmp(ft_call_value_of("HOME"), ft_call_value_of("PWD")))
		promt = ft_strjoin_and_free_string1(promt, "~");
	else
		promt = ft_strjoin_and_free_string1(promt, ptr_dir);
	promt = ft_strjoin_and_free_string1(promt, " ");
	promt = ft_strjoin_and_free_string1(promt, ft_call_value_of("USER"));
	promt = ft_strjoin_and_free_string1(promt, "$ ");
	ft_putstr(promt);
	g_term.default_cursor_pos = ft_strlen(promt) + 1;
	free(promt);
}

// void executor(t_astnode *ast)  // fore debug
// {
// 	printBinaryTree(ast);
// 	(void)ast;
// }

static void	ft_execute(char *input)
{
	t_token	*tokens;
	t_astnode *ast;

	ast = NULL;
	if (input)
	{
		if ((tokens = lexical_analysis(input)) != NULL)
			if ((ast = syntax_analysis(tokens)) != NULL)
				executor(ast);
		// need to free tokens after, i can free them all at executor
	}
}

//enable later
// static void	signal_handeler(int signo)
// {
// 	if (signo == SIGINT)
// 	{
// 		ft_putchar_fd('\n', STDOUT_FILENO);
// 		ft_promt();
// 		signal(SIGINT, signal_handeler);
// 	}
// }

// without line_edition
// static char	*get_input(int level)
// {
// 	char *line;

// 	if ((get_next_line(STDOUT_FILENO, &line)) <= 0)
// 		return (NULL); // may be return ft_strdup("");
// 	if (is_open_dquote(line, level))
// 	{
// 		ft_putstr("dquote> ");
// 		line = ft_strjoin_and_free_string1(line, "\n");
// 		line = ft_strjoin_and_free_2string(line, get_input((int)2));
// 	}
// 	return (line);
// }

static char	*get_input(int level)
{
	char *line;

	if ((line = ft_getline()) == NULL)
		return (ft_strdup(""));
	if (is_open_dquote(line, level))
	{
		ft_putstr("dquote> ");
		line = ft_strjoin_and_free_string1(line, "\n");
		line = ft_strjoin_and_free_2string(line, get_input((int)2));
	}
	return (line);
}

int		main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	env = ft_new_env(NULL, NULL, 0, envp);
	while (1)
	{
		ft_promt();
		//signal(SIGINT, signal_handeler);
		input = get_input((int)1);
		ft_execute(input);
		free(input);
	}
	return (EXIT_SUCCESS);
}
