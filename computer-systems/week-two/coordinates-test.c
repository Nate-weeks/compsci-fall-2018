/*
coordinates-test
executable test file for coordinates linked list
Nate Weeks Sept 2018
*/

#include <stdio.h>
#include "coordinates.h"

int main(){
  coordinate_list list = new_coordinate_list();
  while(1){
  add_coordinate(list);
  if(list->length == 10){
    break;
  }
}
  print_coordinate_list_reversed(list);
  free_coordinate_list(list);
  return 0;
}
