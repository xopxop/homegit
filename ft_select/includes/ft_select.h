/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:53:17 by dthan             #+#    #+#             */
/*   Updated: 2020/07/15 19:00:34 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termios.h>
# include <curses.h>
# include <termcap.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# define ENTER_KEY(str) ft_strequ(str, "\n")
# define SPACE_KEY(str) ft_strequ(str, " ")
# define ESCAPE_KEY(str) ft_strequ(str, "\033")
# define BACKSPACE_KEY(str) ft_strequ(str, "\177")
# define DELETE_KEY(str) ft_strequ(str, "\033[3~")
# define UPWARDS_ARROW(str) ft_strequ(str, "\033[A")
# define DOWNWARDS_ARROW(str) ft_strequ(str, "\033[B")
# define RIGHTWARDS_ARROW(str) ft_strequ(str, "\033[C")
# define LEFTWARDS_ARROW(str) ft_strequ(str, "\033[D")
# define CTRL_Z "\x1A"

typedef struct		s_elem
{
	char			*av;
	int				max_length;
	int				selected;
	int				position;
}					t_elem;

typedef struct		s_lst
{
	t_elem			elem;
	struct s_lst	*next;
	struct s_lst	*previous;
}					t_lst;

typedef struct		s_terminal
{

	struct termios	new_attributes;
	struct termios	old_attributes;
	char			term_buffer[2048];
	char			*termtype;
	int				cols;
	int				rows;
}					t_terminal;

typedef struct		s_select
{
	t_lst			*head;
	t_lst			*last;
	t_terminal		term;
}					t_select;

t_select g_select;

int		char_to_term(int c);
t_lst	*ft_creat_elem(char *input);
void	ft_display(void);
void	ft_space_key(t_lst *head);
void	ft_remove_elem(t_lst **head);
void	ft_move(char *buf);
void	move_right(t_lst *head);
void	move_left(t_lst *last);
void	move_down(t_lst *head);
void	move_up(t_lst *last, t_lst *head);
int		ft_finding_longest_elem(t_lst *lst);
int		count_selected_elem(t_lst *head);
int		ft_count_elems(t_lst *lst);
void	free_elems(t_lst **head, t_lst **last);
void	restore_old_term_config(void);
void	signal_initialization(void);

#endif