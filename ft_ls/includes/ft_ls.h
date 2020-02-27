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


# define LONG_LIST_FORMAT 1
# define LIST_SUBDIR_RECUSIVELY 2
# define LIST_HIDDEN 4
# define REVERSE_ORDER 8
# define SORT_BY_NEWEST_FIRST 16

# define OK 0
# define MINOR_PROBLEMS 1
# define SERIOUS_TROUBLE 2

typedef struct      s_dinfo
{
    char            *dir_name;
    struct s_dinfo  *next;
}                   t_dinfo;

typedef struct      s_finfo
{
    
}                   t_finfo;

/*
**  options.c
*/

int get_options(char *input, int *options);

/*
** dir_info.c
*/

int get_dir(char *input, t_dinfo **ldir);

#endif
