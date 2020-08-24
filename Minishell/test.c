#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalhandler(int signum) {
  printf("\n SIGINT caught : %d", signum);
}

int main() {
  signal(SIGINT, signalhandler);

  while (1) {
    printf("\n looping : inside main()");
    sleep(1);
  }
}
