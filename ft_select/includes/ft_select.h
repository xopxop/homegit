/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:53:17 by dthan             #+#    #+#             */
/*   Updated: 2020/05/20 09:30:11 by dthan            ###   ########.fr       */
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

# define SPACE_KEY 32
# define ENTER_KEY 10
# define UPWARDS_ARROW(str) ft_strequ(str, "\033[A")
# define DOWNWARDS_ARROW(str) ft_strequ(str, "\033[B")
# define RIGHTWARDS_ARROW(str) ft_strequ(str, "\033[C")
# define LEFTWARDS_ARROW(str) ft_strequ(str, "\033[D")

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

	struct termios	term_attributes;
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


#endif