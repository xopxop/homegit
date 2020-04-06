/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 05:59:47 by dthan             #+#    #+#             */
/*   Updated: 2020/04/04 05:59:48 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_replace_tokens_only(char **tokens)
{
	int i;
	char *ptr;

	i = 0;
	while (tokens[++i])
		if (tokens[i][0] == '$')
		{
			ptr = ft_strdup(ft_call_value_of(&tokens[i][1]));
			free(tokens[i]);
			tokens[i] = ptr;
		}
	return (tokens);
}

char	**ft_creat_new_and_replace_tokens(char **tokens, int size)
{
	char **new_tokens;
	char **ptr;
	int i;

	i = -1;
	new_tokens = (char**)malloc(sizeof(char*) * (size + 1));
	ptr = new_tokens;
	*ptr = ft_strdup(tokens[++i]);
	while (tokens[++i])
	{
		if (tokens[i][0] == '$')
			if (!ft_strncmp(&tokens[i][1], ft_call_var(&tokens[i][1]), ft_strlen(&tokens[i][1])))
				*ptr = ft_strdup(ft_call_value_of(&tokens[i][1]));
			else
				continue ;
		else
			*ptr = (ft_strdup(tokens[i]));
		ptr++;
	}
	ft_arraydel(tokens);
	return (new_tokens);
}

char	**ft_change_tokens(char **tokens)
{
	int nb_invalid_env_var;
	int i;

	i = 0;
	nb_invalid_env_var = 0;
	while (tokens[++i])
		if (ft_strncmp(&tokens[i][1], ft_call_var(&tokens[i][1]), ft_strlen(&tokens[i][1])))
			nb_invalid_env_var++;
	tokens = (nb_invalid_env_var > 0) ? ft_creat_new_and_replace_tokens \
			(tokens, (i + nb_invalid_env_var + 1)) : ft_replace_tokens_only(tokens);
	return (tokens);
}
