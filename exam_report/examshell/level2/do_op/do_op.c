#include "do_op.h"

int main(int argc, char **argv)
{
	int result;

	if (argc == 4)
	{
		if (*argv[2] == '+' || *argv[2] == '-' || *argv[2] == '/' || \
				*argv[2] == '*' || *argv[2] == '%')
		{
			if (*argv[2] == '+')
				result = atoi(argv[1]) + atoi(argv[3]);
			else if (*argv[2] == '-')
				result = atoi(argv[1]) - atoi(argv[3]);
			else if (*argv[2] == '/')
				result = atoi(argv[1]) / atoi(argv[3]);
			else if (*argv[2] == '*')
				result = atoi(argv[1]) * atoi(argv[3]);
			else if (*argv[2] == '%')
				result = atoi(argv[1]) % atoi(argv[3]);
			printf("%d", result);
		}
	}
	printf("\n");
	return (0);
}
