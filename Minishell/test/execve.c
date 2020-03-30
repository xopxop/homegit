#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	ft_string_count(char **input)
{
	int ct;

	ct = 0;
	while (*input)
	{
		ct++;
		input++;
	}
	return (ct);
}

char	**ft_load_config(char **variable)
{
	char		**list_loaded_variables;
	char		**ptr;

	list_loaded_variables = (char**)malloc(sizeof(char*) * (ft_string_count(variable) + 1));
	ptr = list_loaded_variables;
	while (*variable)
	{
		*ptr = strdup(*variable);
		variable++;
		ptr++;
	}
	*ptr = NULL;
	return (list_loaded_variables);
}

int
main(int argc, char *argv[], char **envp)
{
	char *newargv[] = { "ls", NULL };
    char **newenviron;
	char *binaryPath = "/bin/ls";
	char *args[] = {binaryPath, "-l", NULL};

	newenviron = ft_load_config(envp);
	execve(binaryPath, args, newenviron);
    perror("execve");   /* execve() returns only on error */
    exit(EXIT_FAILURE);
}

