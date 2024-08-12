#include <stdio.h>
#include <stdlib.h>
#include "interface_def.c"

// in this file, we define a type that satisfy the "interfaces"


// its time to define types that satisfy these interfaces
typedef struct {
  int x; int y; int z;

  //Now include the "interfaces"
  display_if_t* display_if;
  stringer_if_t* stringer_if;
} int_vec ;

// Now we have "declared" that the int_vec type above satisfy the display_if and stringer_if
// But we haven't "implemented" it yet
int int_vec_to_string(void* self, char* string) {
  // we "know" that self is of int_vec type
  int_vec* vec_self = self;
  return sprintf(string, "int_vec {x=%0d, y=%0d, z=%0d}", vec_self->x, vec_self->y, vec_self->z);
}

// Now we define a static vtable instance for the int_vec type
// for to_string interface
static stringer_if_t int_vec_stringer_if = {
  .to_string = int_vec_to_string
};

// implementation for display method
void int_vec_display(void* self) {
  int_vec* vec_self = self;
  printf("int_vec {x=%0d, y=%0d, z=%0d} \n", vec_self->x, vec_self->y, vec_self->z);
}

static display_if_t int_vec_display_if = {
  .display = int_vec_display
};


// we create the int_vec  type instance through the "constructor" 
// this will also create the pointer for the interface also
int_vec* create_int_vec(int x, int y, int z) {
  int_vec* self = (int_vec*)malloc(sizeof(int_vec));
  self->x = x;
  self->y = y;
  self->z = z;

  // Now the instance has "vtable" pointer
  self->display_if = &int_vec_display_if;
  self->stringer_if = &int_vec_stringer_if;
  return self;
}
