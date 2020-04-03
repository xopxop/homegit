#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_signal_interrupt(int sig)
{
  printf("I got signal %d\n", sig);
  (void) signal(SIGINT, SIG_DFL);
}

int main()
{
	int *p = NULL;
	(void)signal(SIG, SIG_DFL);

	*p = 45;
	while(1) {
    printf("Waiting for interruption...\n");
    sleep(1);
	}
}