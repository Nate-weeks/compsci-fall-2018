#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp){
  if(execve("/bin/ls", argv, envp) < 0){
    printf("some bad shit happened");
    exit(0);
  };
  return 0;
}
