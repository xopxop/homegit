/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:00 by dthan             #+#    #+#             */
/*   Updated: 2020/07/22 04:11:18 by dthan            ###   ########.fr       */
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



// old
# define ENTER_KEY(str) ft_strequ(str, "\n")
# define UPWARDS_ARROW(str) ft_strequ(str, "\033[A")
# define DOWNWARDS_ARROW(str) ft_strequ(str, "\033[B")
# define RIGHTWARDS_ARROW(str) ft_strequ(str, "\033[C")
# define LEFTWARDS_ARROW(str) ft_strequ(str, "\033[D")
# define X_AXIS	0
# define Y_AXIS	1

typedef	struct		s_cusor
{
	int				coordinate[2];
}					t_cusor;

/*** not use ***/
typedef struct		s_terminal
{

	struct termios	new_attributes;
	struct termios	old_attributes;
	char			term_buffer[2048]; // maybe need to check the term_buffer
	char			*termtype;
	int				cols;
	int				rows;
	int				default_cursor_pos;
	struct s_cusor	cursor;
}					t_terminal;
/******/

typedef struct erow {
	int size;
	char *chars;
} erow;

enum editorKey {
	BACKSPACE = 127,
	ARROW_LEFT = 1000,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	DEL_KEY
};

struct editorConfig {
	int cx0, cy0;
	int cx, cy;
	int rowoff;
	int len;
	int screenrows;
	int screencols;
	int numrows;
	erow row;
	struct termios		orig_termios;	
};

struct editorConfig E;

struct abuf {
	char *b;
	int len;
};

#define ABUF_INIT {NULL, 0}

/*** not used ***/
typedef struct		s_line_info
{
	char			*returned_line;
	int				line_length;
	int				cusor_pos;
}					t_line_info;

t_terminal	g_term;
/******/
char	*ft_getline(void);

#endif