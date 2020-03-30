/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 04:58:25 by dthan             #+#    #+#             */
/*   Updated: 2020/02/21 04:58:26 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** opendir <sys/types.h><dirent.h>
** ==> open a directory
** readdir <dirent.h>
** ==> read a direcotry.
** closedir <sys/types.h><dirent.h>
** ==> close a directory.
** stat <sys/types.h><sys/stat.h><unistd.h>
** ==> Display file or file system status.
** lstat <sys/types.h><sys/stat.h><unistd.h>
** ==> get file status.
** getpwuid <sys/types.h><pwd.h>
** ==> get password file entry.
** getgrgid <sys/types.h><grp.h>
** ==> get group file entry.
** time -none-
** ==> run programs and summarize system resource usage.
** ctime <grp.h>
** ==> transform date and time to broken-down time or ASCII
** readlink -none-
** ==> print resolved symbolic links or canonical file names.
** perror <stdio.h>
** ==> print a system error message.
** strerror <string.h>
** ==> return string describing error number.
*/

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"
# include <errno.h>
# include <time.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# define LONG_LIST_FORMAT 1
# define LIST_SUBDIR_RECUSIVELY 2
# define LIST_HIDDEN 4
# define REVERSE_ORDER 8
# define SORT_BY_NEWEST_FIRST 16

# define STD_ERR 2
# define STD_OUT 1

# define OPTIONS_ERROR 256 // WHere this one uses for?

# define OK 0
# define MINOR_PROBLEMS 1
# define SERIOUS_TROUBLE 2

# define YES 1
# define NO 0

typedef struct		s_max
{
	int				width_of_link;
	int				width_of_user_name;
	int				width_of_group_name;
	int				width_of_size;
}					t_max;

typedef struct		s_min
{
	int				width_of_link;
	int				width_of_user_name;
	int				width_of_group_name;
	int				width_of_size;
}					t_min;

typedef struct		s_stat
{
	char			*name;
	char			*path;
	char			*user_name;
	char			*group_name;
	char			*time;
	char			*file_permission;
	char			type;
	char			*path_sym_link;
	int				is_hidden;
	int				allow_open;
	struct stat		stats;
	struct s_min	min_of;
}					t_stat;

typedef struct		s_node
{
	t_stat			status;
	struct s_node	*next;
}					t_node;

typedef struct		s_window
{
	int				columns;
	int				rows;
	int				lst_len;
	int				lm;
	int				max;
}					t_window;

typedef struct		s_args
{
	struct s_node	*file;
	struct s_node	*dir;
}					t_args;

/*
** Main
*/

void				ft_get_file_info(t_node *node, char *filename, char *path,\
					int *ret);
void				ft_recusion(t_node *parent, int options, int *ret);
void				ft_ls(t_args parent, int options, int *ret);
void				ft_get_arguments(char **input, int *options, t_args *lst,\
					int *ret);

/*
**  Error
*/

void				ft_err_can_not_access(char *invalid_file_or_dir);
void				ft_err_invalid_option(char *invalid_option, int dashno);
void				ft_err_malloc();
void				ft_err_permission_dinied(char *dirname);
void				ft_err_can_not_read_link(char *path);

/*
**  options.c
*/

int					get_options(char *input);
int					get_short_options(char *input);
int					get_long_option(char *input);

/*
** Parser.c
*/

int					ft_isoptions(char chr);
int					ft_is_short_options(char chr1, char chr2);
int					ft_is_long_option(char chr1, char chr2);
int					ft_isfile(char *dir_name, int *ret);

/*
** Free
*/
void				free_lst(t_node *node);
void				ft_free_larg(t_args *input_file);

/*
** Display
*/

void				display(t_node *parent, t_node *parent_file, int *ret,\
					t_node *lchild, int options);
void				ft_short_list(t_node *lfile, int options);
void				ft_long_list(t_node *parent, t_node *lchild, int options);
void				ft_init_struct_max(t_max *max);

/*
** Sort
*/

void				ft_sort(t_node *lst, int options);
void				ft_sort_alphabet(t_node *lst);
void				ft_sort_rever_alphabet(t_node *lst);
void				ft_sort_time(t_node *lst);
void				ft_swap_stat(t_stat *file1, t_stat *file2);

/*
**  ============================= Utilities ===================================
*/

/*
** Compaser
*/

int					ft_cmp_time(t_node *file1, t_node *file2);
int					ft_cmp_name(t_stat file1, t_stat file2);

/*
** Long list helper
*/

void				ft_print_long_list(t_node *node, t_max max);
void				ft_get_max(t_max *max, t_node *lst, int options);
int					ft_blockct(t_node *lst, int options);

/*
** Short list helper
*/

int					ft_get_terminal_width();
int					ft_get_max_file_name(t_node *node, int options);
void				ft_skip_hidden_node(t_node **node, int options);
int					ft_get_list_size(t_node *node, int options);
char				***ft_creat_table(int row, int col);
char				***ft_putlist_into_table(char ***table, t_node *node,\
					int row, int col, int options);
void				ft_print_short_list(char ***table, int width, int row,\
					int col);

/*
** Initializer
*/

void				initialize_struct(t_node *node);
void				ft_init_struct_max(t_max *max);

/*
** Info Collecter
*/

char				*ft_get_user_name(uid_t id);
char				*ft_get_group_name(gid_t id);
char				*ft_get_time(time_t time);
char				*ft_get_file_permission(mode_t mode);
char				ft_get_data_type(mode_t mode);

/*
** Info Collecter 2
*/

char				*ft_get_path_sym_link(char *pathname, int *ret);
t_min				ft_get_min(t_node *node);

/*
** Tools
*/

int					ft_numlen(int num);
void				ft_push_node_to_lst(t_node **head, t_node *node);
void				ft_split_input(char *name, t_args *lst, int *ret);

#endif
