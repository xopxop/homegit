/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:39:52 by dthan             #+#    #+#             */
/*   Updated: 2019/11/07 01:10:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define FD_MAX 256
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int	get_next_line(int fd, char **line);

#endif
