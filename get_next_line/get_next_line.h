/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:39:05 by dthan             #+#    #+#             */
/*   Updated: 2019/11/05 14:15:53 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 8
# define MAX_FD 1024 + 1
# define RETURN_VALUE(ret) ret > 0 ? 1 : ret

int	get_next_line(const int fd, char **line);

#endif
