/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 05:33:01 by dthan             #+#    #+#             */
/*   Updated: 2020/03/27 22:30:07 by dthan            ###   ########.fr       */
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

void	ft_recusion(t_node *parent, int options, int *ret)
{
	DIR				*ptr_dir;
	struct dirent	*ptr_entry;
	t_node			*child;
	t_node			*node;

	while (parent)
	{
		if (parent->status.type == 'd' && parent->status.allow_open == YES)
		{
			write(1, "\n", 1);
			if (!(ptr_dir = opendir(parent->status.path)))
			{
				ft_err_permission_dinied(parent->status.name);
				*ret = MINOR_PROBLEMS;
			}
			else
			{
				child = NULL;
				while ((ptr_entry = readdir(ptr_dir)))
				{
					if (!(node = (t_node*)malloc(sizeof(t_node))))
						ft_err_malloc();
					initialize_struct(node);
					ft_get_file_info(node, ptr_entry->d_name, parent->status.path, ret);
					ft_push_node_to_lst(&child, node);
				}
				closedir(ptr_dir);
				ft_sort(child, options);
				display(parent, NULL, 0, child, options);
				ft_recusion(child, options, ret);
				free_lst(child);
			}
		}
		parent = parent->next;
	}
}

void	ft_ls(t_args parent, int options, int *ret)
{
	t_node			*child;
	t_node			*node;
	t_node			*ptr;
	DIR				*ptr_dir;
	struct dirent	*ptr_entry;

	ptr = parent.file;
	while (ptr)
	{
		display(NULL, ptr, 0, NULL, options);
		ptr = ptr->next;
	}
	while (parent.dir)
	{
		child = NULL;
		ptr_dir = opendir(parent.dir->status.path);
		while ((ptr_entry = readdir(ptr_dir)))
		{
			if (!(node = (t_node*)malloc(sizeof(t_node))))
				ft_err_malloc();
			initialize_struct(node);
			ft_get_file_info(node, ptr_entry->d_name, parent.dir->status.path, ret);
			ft_push_node_to_lst(&child, node);
		}
		closedir(ptr_dir);
		ft_sort(child, options);
		display(parent.dir, parent.file, ret, child, options);
		if (options & LIST_SUBDIR_RECUSIVELY)
			ft_recusion(child, options, ret);
		free_lst(child);
		parent.dir = parent.dir->next;
	}
}

void	ft_get_arguments(char **input, int *options, t_args *lst, int *ret)
{
	int		arg_nbr;

	arg_nbr = 1;
	while (input[arg_nbr])
	{
		if (ft_isoptions(input[arg_nbr][0]))
			*options |= get_options(input[arg_nbr]);
		else if (ft_isfile(input[arg_nbr], ret))
			ft_split_input(input[arg_nbr], lst, ret);
		arg_nbr++;
	}
	if (lst->dir == NULL && lst->file == NULL && *ret == 0)
		ft_split_input(".", lst, ret);
}

int	main(int ac, char **av)
{
	int		options;
	t_args	input_file;
	int		ret;

	ret = 0;
	options = 0;
	input_file.file = NULL;
	input_file.dir = NULL;
	(void)ac;
	ft_get_arguments(av, &options, &input_file, &ret);
	ft_ls(input_file, options, &ret);
	ft_free_larg(&input_file); //need to fix
	if (ret == 1)
		return (MINOR_PROBLEMS);
	return (EXIT_SUCCESS);
}
