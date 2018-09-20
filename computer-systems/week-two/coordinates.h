/*
coordinates.h
typedefs for coordinates.c
Nate Weeks Sept 2018
*/

typedef struct _coordinate *coordinate;
struct _coordinate {
  coordinate next;
  coordinate prev;
  int x;
  int y;
};

typedef struct _coordinate_list *coordinate_list;
struct _coordinate_list{
  int length;
  coordinate first;
  coordinate last;
};

coordinate new_coordinate(int x, int y);
coordinate_list new_coordinate_list();
void push(coordinate_list list, coordinate new_coordinate);
void add_coordinate(coordinate_list list);
void print_coordinate_list_reversed();
void free_coordinate(coordinate coord);
void free_coordinate_list(coordinate_list list);
