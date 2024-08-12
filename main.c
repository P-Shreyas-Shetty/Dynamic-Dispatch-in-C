#include "int_vec.c"
#include "float_vec.c"
#include "interface_def.c"


// A function that relies on "dynamic dipatch"
void call_display(void* self, display_if_t* display_if) {
  display_if->display(self);
}


int main() {
  int_vec* v0 = create_int_vec(1,2,3);
  float_vec* v1 = create_float_vec(2.0,3.0,1.0);
  // we pass the pointer to display_if 
  call_display(v0, v0->display_if);
  call_display(v1, v1->display_if);
  return 0;
}
