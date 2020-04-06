#include <unistd.h>
#include <stdio.h>

int main()
{
	char buff[200];

	chdir("/home,asd");
	printf("%s\n", getcwd(buff, 200));
	return (0);
}