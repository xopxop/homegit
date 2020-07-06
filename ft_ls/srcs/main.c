/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 05:33:01 by dthan             #+#    #+#             */
/*   Updated: 2020/07/06 17:33:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_get_file_info(t_node *node, char *filename, char *path, int *ret)
{
	struct stat	filestat;

	node->status.name = ft_strdup(filename); //ft_get_name && ft_get_path to advoid the edgy case
	if (path == NULL)
		node->status.path = ft_strdup(filename);
	else if (!ft_strcmp("/", path))
		node->status.path = ft_strjoin("/", node->status.name);
	else
		node->status.path = ft_strjoin_and_free_string1(ft_strjoin(path, "/"), node->status.name);
	lstat(node->status.path, &filestat);
	node->status.type = ft_get_data_type(filestat.st_mode);
	if (node->status.type == 'l')
		node->status.path_sym_link = ft_get_path_sym_link(node->status.path, ret);
	node->status.file_permission = ft_get_file_permission(filestat.st_mode);
	node->status.user_name = ft_get_user_name(filestat.st_uid);
	node->status.group_name = ft_get_group_name(filestat.st_gid);
	node->status.time = ft_get_time(filestat.st_mtime);
	node->status.stats = filestat;
	node->status.min_of = ft_get_min(node);
	if (node->status.name[0] == '.')
		node->status.is_hidden = YES;
	if (!(ft_strcmp(".", node->status.name)) || !(ft_strcmp("..", node->status.name)))
		node->status.allow_open = NO;
	node->next = NULL;
}

t_node*	ft_get_lchild(t_node *parent_dir, int *ret)
{
	t_node			*node;
	t_node			*lchild;
	DIR				*ptr_dir;
	struct dirent	*ptr_entry;
	
	lchild = NULL;
	ptr_dir = opendir(parent_dir->status.path);
	while ((ptr_entry = readdir(ptr_dir)))
	{
		if (!(node = (t_node*)malloc(sizeof(t_node))))
				ft_err_malloc();
		initialize_struct(node);
		ft_get_file_info(node, ptr_entry->d_name, parent_dir->status.path, ret);
		ft_push_node_to_lst(&lchild, node);
	}
	closedir(ptr_dir);
	return (lchild);
}

void	ft_recusion(t_node *parent, t_args output)
{
	DIR				*ptr_dir;
	t_node			*child;

	while (parent)
	{
		if (!(output.options & LIST_HIDDEN) && parent->status.is_hidden == YES)
			;
		else if (parent->status.type == 'd' && parent->status.allow_open == YES)
		{
			write(1, "\n", 1);
			if (!(ptr_dir = opendir(parent->status.path)))
			{
				ft_err_permission_dinied(parent->status.name);
				(&output)->ret = MINOR_PROBLEMS;  //need to check this
			}
			else
			{
				closedir(ptr_dir);
				child = ft_get_lchild(parent, &output.ret);
				ft_sort(&child, output.options);
				ft_printf("%s:\n", parent->status.path);
				display(parent, NULL, child, output);
				ft_recusion(child, output);
				free_lst(child);
			}
		}
		parent = parent->next;
	}
}

int		ft_lstcount(t_node *lst)
{
	int	ct;

	ct = 0;
	while (lst)
	{
		lst = lst->next;
		ct++;
	}
	return (ct);
}

void	ft_ls(t_args parent)
{
	t_node			*child;
	int				print_dname;

	print_dname = (ft_lstcount(parent.dir) == 1 && parent.file == NULL && \
		!(parent.options & LIST_SUBDIR_RECUSIVELY)) ? NO : YES;
	if (parent.file)
	{
		display(NULL, parent.file, NULL, parent);
		(parent.dir) ? ft_putchar('\n') : 0;
	}
	while (parent.dir)
	{
		(print_dname == YES) ? ft_printf("%s:\n", parent.dir->status.path) : 0;
		child = ft_get_lchild(parent.dir, &parent.ret);
		ft_sort(&child, parent.options);
		display(parent.dir, NULL, child, parent);
		(parent.options & LIST_SUBDIR_RECUSIVELY) ? \
			ft_recusion(child, parent) : 0;
		free_lst(child);
		parent.dir = parent.dir->next;
		(parent.dir != NULL) ? ft_putchar('\n') : 0;
	}
}

void	ft_get_arguments(char **input, t_args *output)
{
	int		arg_nbr;

	arg_nbr = 1;
	while (input[arg_nbr])
	{
		if (ft_isoptions(input[arg_nbr][0]))
			output->options |= get_options(input[arg_nbr]);
		else if (ft_isfile(input[arg_nbr], &(output->ret)))
			ft_split_input(input[arg_nbr], output);
		arg_nbr++;
	}
	if (output->dir == NULL && output->file == NULL && output->ret == 0)
		ft_split_input(".", output);
	ft_sort_alphabet(output->file);
	ft_sort_alphabet(output->dir);
}

int	main(int ac, char **av)
{
	t_args	output;

	output.ret = 0;
	output.options = 0;
	output.file = NULL;
	output.dir = NULL;
	(void)ac;
	ft_get_arguments(av, &output);
	ft_ls(output);
	ft_free_larg(&output); //need to fix
	if (output.ret == 1)
		return (MINOR_PROBLEMS);
	return (EXIT_SUCCESS);
}
