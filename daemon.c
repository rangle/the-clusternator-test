#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void make_daemon(void) {
  pid_t pid;
  pid_t sid;

  pid = fork();
  if(pid < 0) {
    printf("Error: can not fork");
    exit(-1);
  } else if(pid > 0) {
    printf("Started daemon.");
    exit(0);
  }

  umask(0);


  sid = setsid();
  if (sid < 0) {
    exit(-1);
  }
}

int main(void) {
  int i;
  i = 0;

  printf("STARTING\n");

  while(1) {
    printf("%d\n", i);
    i++;
    sleep(1);
  }
  
  return 0;
}

// Commenting to force diff
// another one.
// another one.
// another one.
// another one.
