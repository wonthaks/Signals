/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool printTuring = false;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printTuring = true;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  while(1) {
    alarm(1); //Schedule a SIGALRM for 1 second
    if (printTuring) {
      printf("Turing was right!\n");
      printTuring = false;
    }
    sleep(1);
  } //busy wait for signal to be delivered
  exit(1); //exit after printing (moved from handler function)
  return 0; //never reached
}