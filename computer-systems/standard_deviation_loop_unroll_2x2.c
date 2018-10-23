/** c program by Nate Weeks to calculate standard deviation of an array **/

#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


double calculate_mean(double *array, int length){
  int i;
  double sum,sum_one,sum_two;
  double mean;
  sum_one = 0;
  sum_two = 0;
  for(i=0; i<length-1; i+=2){
    sum_one += (array[i]);
    sum_two += (array[i+1]);
  };
  for(; i<length; i++){
    sum_one += (array[i]);
  }
  sum = sum_one + sum_two;
  mean = sum / length;
  return mean;
}

double calculate_standard_deviation(double *array, int length, double mean){
  int i, j;
  double sum, sum_one, sum_two;
  double result;
  sum = 0;
  sum_one = 0;
  sum_two = 0;
  for(i=0; i<length-1; i+=2){
    sum_one += pow((array[i] - mean), 2);
    sum_two += pow((array[i+1] - mean), 2);
  }
  sum = sum_one + sum_two;
  for(; i<length; i++){
    sum += pow((array[i] - mean), 2);
  }
  result = sqrt(sum);
  return result;
}

int main(){
  double mean;
  double standard_deviation;
  double arr[1000000];
  int i;

/* populate an array with random numbers */
  srand(42);
  for(i=0; i<1000000; i++){
    arr[i] = rand();
  }
/*calculate the mean and sd of that array 100 times */
  clock_t begin = clock();
  for(i=0; i<100; i++){
  mean = calculate_mean(arr, 1000000);
  standard_deviation = calculate_standard_deviation(arr, 1000000, mean);
}
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  /* print the sd and time_spent */

  printf("stand deviation: %f\n", standard_deviation);
  printf("time: %f\n", time_spent);
  return 0;
}
