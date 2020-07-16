/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:22:00 by dthan             #+#    #+#             */
/*   Updated: 2020/07/16 02:46:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITION_H
# define LINE_EDITION_H
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
# define UPWARDS_ARROW(str) ft_strequ(str, "\033[A")
# define DOWNWARDS_ARROW(str) ft_strequ(str, "\033[B")
# define RIGHTWARDS_ARROW(str) ft_strequ(str, "\033[C")
# define LEFTWARDS_ARROW(str) ft_strequ(str, "\033[D")

typedef struct		s_terminal
{

	struct termios	new_attributes;
	struct termios	old_attributes;
	char			term_buffer[2048]; // maybe need to check the term_buffer
	char			*termtype;
	int				cols;
	int				rows;
	int				default_cursor_pos;
	int				cursor_pos;
}					t_terminal;

t_terminal	g_term;

char	*ft_getline(void);

#endif