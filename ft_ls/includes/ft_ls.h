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

typedef struct      s_dir
{
    char            *name;
    struct stat     stat;
    struct s_dir    *next;
    struct s_file   *file;
}                   t_dir;

typedef struct      s_file
{
    char            *name;
    char            *path;
    struct  stat    stat;
    char            *user_name;
    char            *group_name;
    int            link;
    int             size;
    char            *time;
    struct  s_file  *next;
}                   t_file;

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
void get_dir(char *dir_name, t_dir **ldir);

//////

int ft_isoptions(char chr);
int ft_is_short_options(char chr1, char chr2);
int ft_is_long_option(char chr1, char chr2);
int ft_isdir(char *dir_name);


#endif
