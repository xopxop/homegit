/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 01:43:07 by dthan             #+#    #+#             */
/*   Updated: 2019/11/06 01:54:11 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
//	int fd2;
	int ret;
//	int ret2;
	int line;
//	int line2;
	char *buff;
//	char *buff2;

	line = 0;
//	line2 = 0;
	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		close(fd);
//		fd2 = open(argv[2], O_RDONLY);
//		while ((ret2 = get_next_line(fd2, &buff2)) > 0)
//		{
//			printf("[Return: %d] Line #%d: %s\n", ret2, ++line2, buff2);
//			free(buff2);
//		}
//		printf("[Return: %d] Line #%d: %s\n", ret2, ++line2, buff2);
//		if (ret2 == -1)
//			printf("-----------\nError\n");
//		else if (ret2 == 0)
//			printf("-----------\nEnd of file\n");
//		close(fd2);
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &buff)) > 0)
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of stdin\n");
		close(fd);
	}
	return (0);
}
