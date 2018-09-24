/*
 * bomblab_warmup.c
 *
 * On shannon.marlboro.college :
 * 
 *   $ gcc -Og bomblab_warmup.c -o warmup
 *
 *   (The -Og option means "optimize to help debugging".)
 *
 *   $ ./warmup
 *   1: What is the magic word? ummm
 *   BOOM!
 *
 *   $ ./warmup
 *   1: What is the magic word? magick
 *   2: What is the number? 13
 *   Success.
 *
 * Your mission : use (gdb, objdump, strings, ...) to figure out what 
 * to type from the ./warmup file, not from this source file.
 *
 *   $ objdump -d warmup > warmup.objdump
 *   $ strings warmup > warmup.strings
 *
 *   $ gdb warmup
 *   ... see ./gdb_notes.txt for some ideas.
 *
 * Jim M | Sep 2018 | MIT License
 */

#include <stdio.h>    /* printf, scanf */
#include <stdlib.h>   /* exit */
#include <string.h>   /* strcmp */

int f(int x){
  return x * 17 + 70;
}

int thing2(){
  int i, scanfresult;
  printf("What is the number? ");
  scanfresult = scanf("%d", &i);
  return f(i) == 0x123 ? 1 : 0;
}

int thing1(){
  char* seekrit = "magick";
  char user_input[32];
  int scanfresult;
  printf("What is the magic word? ");
  scanfresult = scanf("%s", user_input);
  return strcmp(user_input, seekrit) == 0 ? 1 : 0;
}

int main(){
  int result;

  printf("1: ");
  if (! thing1()){
    printf("BOOM!\n");
    exit(1);
  }

  printf("2: ");
  if (! thing2()){
    printf("BOOM!\n");
    exit(1);
  }

  printf("Success.\n");
  return 0;
}
