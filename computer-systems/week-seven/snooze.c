/* snooze.c - a program for interrupting sleep() and outputting
the amount of time slept by installing a signal handler
Nate Weeks - October 2018*/

#include <unistd.h>
#include <stdio.h>
#include "csapp.h"

/*wrapper for sleep that outputs time slept*/
unsigned int snooze(unsigned int secs){
  unsigned int rc = sleep(secs);
  printf("slept for %d of %d secs", secs - rc, secs);
  return rc;
}

/*signal handler that directly returns the function instead of terminating*/
void handler(int sig){
  return;
}

int main(){
  if (signal(SIGINT, handler) == SIG_ERR){    /*install the signal handler*/
    printf("signal error\n");
  }
  snooze(5);
  return 0;
}
