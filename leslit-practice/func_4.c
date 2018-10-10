#include <stdio.h>
#include <stdlib.h>

int func4(edi, esi, edx){
  int eax, ecx;
  eax = edx;
  eax = eax - esi;
  eax = eax/2;
  ecx = eax + 1 * esi;
  if(ecx <= edi) goto L1;
  edx = ecx -1;
  eax = func4(edi, esi, edx);
  eax = eax + eax;
  goto L2;
L1:
  eax = 0;
  if(ecx >= edi) goto L2;
  esi = ecx + 1;
  eax = func4(edi, esi, edx);
  eax = eax + eax + 1;
L2:
  return eax;
}

int main(){
  int answer = func4(7, 0, 14);
  printf("%d", answer);
  return 0;
}
