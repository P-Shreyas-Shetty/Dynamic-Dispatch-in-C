#include <stdio.h>
#include <stdlib.h>
#include "interface_def.c"

// in this file, we define a type that satisfy the "interfaces"


// its time to define types that satisfy these interfaces
typedef struct {
  float x; float y; float z;

  //Now include the "interfaces"
  display_if_t* display_if;
  stringer_if_t* stringer_if;
} float_vec ;

// Now we have "declared" that the float_vec type above satisfy the display_if and stringer_if
// But we haven't "implemented" it yet
int float_vec_to_string(void* self, char* string) {
  // we "know" that self is of float_vec type
  float_vec* vec_self = self;
  return sprintf(string, "float_vec {x=%0f, y=%0f, z=%0f}", vec_self->x, vec_self->y, vec_self->z);
}

// Now we define a static vtable instance for the float_vec type
// for to_string interface
static stringer_if_t float_vec_stringer_if = {
  .to_string = float_vec_to_string
};

// implementation for display method
void float_vec_display(void* self) {
  float_vec* vec_self = self;
  printf("float_vec {x=%0f, y=%0f, z=%0f} \n", vec_self->x, vec_self->y, vec_self->z);
}

static display_if_t float_vec_display_if = {
  .display = float_vec_display
};


// we create the float_vec  type instance through the "constructor" 
// this will also create the pointer for the interface also
float_vec* create_float_vec(float x, float y, float z) {
  float_vec* self = (float_vec*)malloc(sizeof(float_vec));
  self->x = x;
  self->y = y;
  self->z = z;

  // Now the instance has "vtable" pointer
  self->display_if = &float_vec_display_if;
  self->stringer_if = &float_vec_stringer_if;
  return self;
}
