/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:54:57 by dthan             #+#    #+#             */
/*   Updated: 2019/11/07 14:12:04 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static int	gnl_verify_line(char **string, char **line)
{
	int i;
	char	*string_with_line_break;
	char	*ptr_for_string_with_line_break;

	i = 0;
	
	string_with_line_break = *string;
	while(string_with_line_break[i] != '\n')
		if (!string_with_line_break[i++])
			return (0);
	ptr_for_string_with_line_break = &string_with_line_break[i];
	*ptr_for_string_with_line_break = '\0';
	*line = ft_strdup(*string);
	*string = ft_strdup(ptr_for_string_with_line_break + 1);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*string[FD_MAX];
	char		*read_buffer;
	ssize_t		read_value;
	char		*temp_string;

	if (fd < 0 || fd > FD_MAX || !(read_buffer = (char*)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	// THere is something here as well, probleam with a line without any character
	// but line break
	if (string[fd])
		if (gnl_verify_line(&string[fd], line))
			return (1);
	while (read_value = read(fd, read_buffer, BUFF_SIZE))
	{
		read_buffer[read_value] = '\0';
		if (string[fd] == NULL)
			string[fd] = ft_strdup(read_buffer);
		else
		{
			temp_string = string[fd];
			string[fd] = ft_strjoin(temp_string, read_buffer);
			ft_strdel(&temp_string);
		}
		if (gnl_verify_line(&string[fd], line))
		{
			//read_value = 1;
			break ;
		}
	}
	free(read_buffer);
	if (read_value != 0 || string[fd] == NULL || string[fd][0] == '\0')
	{
		if(!read_value && *line)
			*line = NULL;
		return (read_value);
	}
	// This part handle the NULL character at the end of the reading
	// when read_value = 0; NOTE: result is the same, do we really need these 3 last line?
	// YES, there is a case for this, but now i dont know why?
	*line = string[fd];
	string[fd] = NULL;
	return (2);
}
