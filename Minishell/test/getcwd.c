#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int main (void) {
	char buf[PATH_MAX];

	getcwd(buf, PATH_MAX);
	printf("%s", buf);
	return (0);
}