/****
Project euler number 9
Nate Weeks September 2018
****/

#include <stdio.h>

int main(){
  int a;
  int b;
  int c;
  int total;
  int i;

  for (a=1;a<1000;a++){
    for (b=a+1;b<1000;b++){
      c = 1000 - a - b;
      if(a*a + b*b == c*c){
        printf("a = %d, b = %d, c = %d\n", a, b, c);
        total = a * b * c;
        printf("the total of a * b * c = %d\n", total);
      };
    };
  };
  return 0;
};
