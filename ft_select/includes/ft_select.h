/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:53:17 by dthan             #+#    #+#             */
/*   Updated: 2020/05/16 16:17:32 by dthan            ###   ########.fr       */
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

# define SPACE_KEY 20
# define ENTER_KEY 10
# define UPWARDS_ARROW 24
# define DOWNWARDS_ARROW 25
# define RIGHTWARDS_ARROW 26
# define LEFTWARDS_ARROW 27

typedef struct		s_terminal{
	struct termios	term_attributes;
	char			term_buffer[2048];
	char			*termtype;
}					t_terminal;

#endif