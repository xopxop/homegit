/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:22:30 by dthan             #+#    #+#             */
/*   Updated: 2019/11/06 01:39:16 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static	int gnl_verify_line(char **stack, char **line)
{
	char	*temp_stack;
	char	*strchr_stack;
	int	i = 0;

	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
		if (!strchr_stack[i++])
			return (0);
	temp_stack = &strchr_stack[i];
	*temp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(temp_stack + 1);
	return (1);
}

static	int	gnl_read_file(int fd, char *heap, char **stack, char **line)
{
	int	ret;
	char	*tmp_stack;

	while((ret = read(fd, heap, BUFF_SIZE)) > 0)
		

int	get_next_line(const in fd, char **line)
{
	static char *stack[MAX_FD];
	char *heap;
	int i = 0;
/*
 * Error check:
 * - File descritor must be positive and smaller than maximum that the sytem
 *   can handle
 * - return value of read() must be > 0, which returns the number of bytes are
 *   read, EOF is returened with 0
 * - Memmory allocation not fail
*/
	if ((fd < 0 || fd >= MAX_FD) || !(heap = (char*)ft_memalloc(sizeof(char) \
		* BUFF_SIZE + 1)) || (read(fd, stack[fd], 0) < 0))
		return (-1);
	if (stack[fd])
		if (gnl_verify_line(&stack[fd], line))
			return (1);
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	ret = gnl_read_file(fd, heap, &stack[fd], line);
