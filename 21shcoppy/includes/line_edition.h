/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:00 by dthan             #+#    #+#             */
/*   Updated: 2020/07/23 23:43:13 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITION_H
# define LINE_EDITION_H
# include "../libft/includes/libft.h"
// # include <unistd.h>
// # include <sys/ioctl.h>
// # include <stdlib.h>
// # include <termios.h>
// # include <curses.h>
// # include <termcap.h>
// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h>
// # include <signal.h>

/*** for now ***/
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
/******/

/*** define ***/
#define CTRL_KEY(k) ((k) & 0x1f)
#define ABUF_INIT {NULL, 0}

enum editorKey {
	BACKSPACE = 127,
	ARROW_LEFT = 1000,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	DEL_KEY
};

/***************DEFINE STRUCT ***************/

typedef struct	s_tempstr
{
	char		*tempStr;
	int			tempSize;
}				t_tempstr;

typedef struct	s_coordinate
{
	int			cx;
	int			cy;
}				t_coordinate;

typedef struct			s_cusor
{
	struct s_coordinate	startPos;
	struct s_coordinate	currentPos;
	int					atLine;
}						t_cursor;

typedef struct			s_lineEditorConfig
{
	struct termios		orig_termios;	
	struct s_cusor		cursor;
	int					screenrows;
	int					screencols;
}						t_lineEditorConfig;

typedef struct			s_buffer
{
	char				*str;
	int					len;
}						t_buffer;

typedef struct			s_line
{
	char				*str;
	int					len;
}						t_line;

t_lineEditorConfig E;

/***************************************/

char	*ft_getline(void);

#endif