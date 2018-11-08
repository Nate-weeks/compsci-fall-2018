/*
coordinates.c
user generated coordinates in a linked list, printed out in reverse order
Nate Weeks Sept 2018
*/
#ifdef COMPILETIME
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include "coordinates.h"

coordinate new_coordinate(int x, int y){
  coordinate new = malloc(sizeof(struct _coordinate));
  new->x = x;
  new->y = y;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

coordinate_list new_coordinate_list(){
  coordinate_list list = malloc(sizeof(struct _coordinate_list));
  list->length = 0;
  list->first = NULL;
  list->last = NULL;
  return list;
}

void push(coordinate_list list, coordinate new_coordinate){
  if (list->length == 0){
    list->first = new_coordinate;
    list->last = new_coordinate;
    list->length = 1;
  }
  else {
    new_coordinate->prev = list->last;
    list->last->next = new_coordinate;
    list->last = new_coordinate;
    list->length++;
  }
}

void add_coordinate(coordinate_list list){
  int x, y;
  printf("please enter an integer for an x coordinate, will finish after 10 have been entered: ");
  scanf("%d", &x);
  printf("please enter an integer for a y coordinate, will finish after 10 have been entered: ");
  scanf("%d", &y);
  push(list, new_coordinate(x, y));
}

void print_coordinate_list_reversed(coordinate_list list){
  coordinate coord = list->last;
  printf("array in reverse order: [");
  while(coord != NULL){
    if(coord->prev == NULL){
      printf("(%d, %d)", coord->x, coord->y);
      coord = coord->prev;
    } else {
      printf("(%d, %d),", coord->x, coord->y);
      coord = coord->prev;
    }
  }
  printf("]");
}

void free_coordinate(coordinate coord){
  free(coord);
}

void free_coordinate_list(coordinate_list list){
  coordinate coord = list->first;
  coordinate next;
  while(coord != NULL){
    next = coord->next;
    free_coordinate(coord);
    coord = next;
  }
  free(list);
}

void *mymalloc(size_t size){
  void *ptr = malloc(size);
  printf("malloc(%d)=%p\n", (int)size, ptr);
  return ptr;
}

void myfree(void *ptr){
  free(ptr);
  printf("free(%p)\n", ptr);
}

#endif
