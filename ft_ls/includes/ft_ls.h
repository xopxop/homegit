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

#include <sys/ioctl.h>

# define LONG_LIST_FORMAT 1
# define LIST_SUBDIR_RECUSIVELY 2
# define LIST_HIDDEN 4
# define REVERSE_ORDER 8
# define SORT_BY_NEWEST_FIRST 16


# define STD_ERR 2
# define STD_OUT 1
/*
**
*/

# define OPTIONS_ERROR 256

# define OK 0
# define MINOR_PROBLEMS 1
# define SERIOUS_TROUBLE 2

# define YES 1
# define NO 0

typedef struct s_max
{
    int width_of_link;
    int width_of_user_name;
    int width_of_group_name;
    int width_of_size;
}t_max;

typedef struct s_min
{
    int width_of_link;
    int width_of_user_name;
    int width_of_group_name;
    int width_of_size;
}t_min;

typedef struct s_stat
{
    char            *name;
    char            *path;
    char            *user_name;
    char            *group_name;
    int            link;
    int             size;
    char            *time;
    char            *file_permission;
    char            type;
    int             is_hidden;
    int             allow_open;
    int             blocks;
    struct stat      stats;
    struct s_min    min_of;
}               t_stat;

typedef struct      s_node
{
    t_stat          status;
    struct  s_node  *next;
}                   t_node;

typedef struct      s_window
{
    int             columns;
    int             rows;
    int             lst_len;
    int             lm;
    int             max;
}                   t_window;

/*
**  Error
*/

void    ft_err_can_not_access(char *invalid_file_or_dir);
void    ft_err_invalid_option(char *invalid_option, int dashno);
void    ft_err_malloc();
void     ft_err_permission_dinied(char *dirname);

/*
**  options.c
*/

int get_options(char *input);
int get_short_options(char *input);
int get_long_option(char *input);

/*
** dir_info.c
*/
// void get_dir(char *dir_name, t_node **ldir);

//////

int ft_isoptions(char chr);
int ft_is_short_options(char chr1, char chr2);
int ft_is_long_option(char chr1, char chr2);
int ft_isfile(char *dir_name, int *ret);

/*
** Free
*/
void free_lfile(t_node *file);

/*
** Display
*/

void display(t_node *lfile, int options);
void ft_print_short_list(t_node *lfile, int options);
void ft_print_long_list(t_node *lfile, int options);

/*
** Get_file_info
*/

char *ft_get_user_name(uid_t id);
char *ft_get_group_name(gid_t id);
char *ft_get_time(time_t time);
char *ft_get_file_permission(mode_t mode);
char ft_get_data_type(mode_t mode);

/*
** Sort
*/

void ft_sort(t_node *lst, int options);
void    ft_sort_alphabet(t_node *lst);
int     cmp(t_stat file1, t_stat file2);
void    ft_swap_stat(t_stat *file1, t_stat *file2);

#endif
