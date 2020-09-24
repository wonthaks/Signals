/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

int numSeconds = 0;

void handler(int signum)
{ //signal handler
  printf("Adding a second!\n");
  numSeconds += 1;
}

void sigintHandler(int signum) {
  printf("Total seconds executed : %d", numSeconds);
  printf("\n");
  exit(1);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, sigintHandler);
  while(1) {
    alarm(1); //Schedule a SIGALRM for 1 second
    sleep(1);
  } //busy wait for signal to be delivered
  exit(1); //exit after printing (moved from handler function)
  return 0; //never reached
}