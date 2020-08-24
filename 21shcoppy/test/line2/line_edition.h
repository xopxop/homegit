#ifndef LINE_EDITION_H
# define LINE_EDITION_H

/*** for now ***/
#include "libft/includes/libft.h"
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
/******/

/*** define ***/
#define CTRL_KEY(k) ((k) & 0x1f)
#define ABUF_INIT {NULL, 0}
#define PROMT "PROMPT: >"
#define OFF_SCREEN "<...>"

enum editorKey {
	BACKSPACE = 127,
	ARROW_LEFT = 1000,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	CTRL_LEFT,
	CTRL_RIGHT,
	CTRL_UP,
	CTRL_DOWN,
	DEL_KEY,
	HOME_KEY,
	END_KEY,
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
	struct s_coordinate prevPos;
	int					atLine;
}						t_cursor;

typedef struct			s_prompt
{
	char				*str;
	int					len;
}						t_prompt;

typedef struct			s_line
{
	char				*str;
	int					len;
}						t_line;

typedef struct			s_lineEditorConfig
{
	struct termios		orig_termios;
	int					startrows;
	int					startcols;
	struct s_prompt		prompt;
	struct s_cusor		cursor;
	struct winsize		ws;
	int					screencells;
	struct s_line		line;
	int					scrolled_lines_above;
	int					scrolled_lines_below;
}						t_lineEditorConfig;

typedef struct			s_buffer
{
	char				*str;
	int					len;
}						t_buffer;

typedef struct			s_selection
{
	int					len;
	int					i;
	int					j;
	int					nb_chars;
	int					min;
	int					max;
	int					to_add;
}						t_selection;

t_lineEditorConfig E;

/*** Terminal ***/
void enableRawMode(void);
void disableRawMode(void);

/*** Init ***/
void initLineEditor(void);

/*** Input ***/
int readKey(void);
int processKeyPress(t_line *line);

/*** Output ***/
void refreshLineEditor(void);

/*** Buffer ***/
void abAppend(t_buffer *ab, char *s);
void abFree(t_buffer *ab);

/*** Getinfo ***/
int getWindowSize(int *rows, int *cols);

/*** Cursor Info ***/
// void updateCursorPos(int *cx, int *cy);
void get_current_cursor(int *cx, int *cy);

/*** Cursor Motion ***/
void editorMoveCursor(int key);

/*** Check Cursor Position ***/
int prev_cursor_position_bottom_right(int prev_strlen);
int prev_cursor_position_top_left(int prev_strlen, int prev_cursor_pos);
int prev_cursor_position_bottom_line(int prev_strlen);

/*** Locate cursor ***/
void locate_cursor(void);

/*** Insert & Delete Char ***/
void insertChar(t_line *line, int c);
void delChar(t_line *line);

/*** Helper ***/
int findind_start_char(int strlen);
int finding_end_char(int strlen, int start);

#endif