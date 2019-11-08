/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:54:57 by dthan             #+#    #+#             */
/*   Updated: 2019/11/08 04:17:38 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int		gnl_verify_line(char **string, char **line)
{
	int		i;
	char		*string_with_line_break;
	char		*ptr_for_string_with_line_break;

	i = 0;
	string_with_line_break = *string;
	while (string_with_line_break[i] != '\n')
		if (!string_with_line_break[i++])
			return (0);
	ptr_for_string_with_line_break = &string_with_line_break[i];
	*ptr_for_string_with_line_break = '\0';
	*line = ft_strdup(*string);
	*string = ft_strdup(ptr_for_string_with_line_break + 1);
	return (1);
}

static int		read_file(int fd, char *read_buffer, char **string, char **line)
{
	char		*temp_string;
	ssize_t		read_value;

	while ((read_value = read(fd, read_buffer, BUFF_SIZE)) > 0)
	{
		read_buffer[read_value] = '\0';
		if (*string)
		{
			temp_string = *string;
			*string = ft_strjoin(temp_string, read_buffer);
			ft_strdel(&temp_string);
		}
		else
			*string = ft_strdup(read_buffer);
		if (gnl_verify_line(string, line))
		{
			read_value = 1;
			break ;
		}
	}
	return (read_value);
}

int			get_next_line(int fd, char **line)
{
	static char	*string[FD_MAX];
	char		*read_buffer;
	ssize_t		read_value;

	if (fd < 0 || fd > FD_MAX || !(read_buffer = (char*)ft_memalloc
		(BUFF_SIZE + 1)) || read(fd, string[fd], 0) < 0)
		return (-1);
	if (string[fd])
		if (gnl_verify_line(&string[fd], line))
			return (1);
	read_value = read_file(fd, read_buffer, &string[fd], line);
	ft_strdel(&read_buffer);
//	free(read_buffer);
	if (read_value != 0 || string[fd] == NULL || string[fd][0] == '\0')
	{
		if (!read_value && *line)
			*line = NULL;
		return (read_value);
	}
	*line = string[fd];
	string[fd] = NULL;
	return (1);
}
