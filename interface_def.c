#ifndef __INTERFACE_DEF_C__
#define __INTERFACE_DEF_C__

// we define tifndefhe interfaces in this file

// This struct defines a stringer interface
// When a type has this struct's pointer as a member,
// we can use it in a "dynamic dispatch" mechanism
// The "self" argument is the pointer to a type
// that "satisfies" this interface
// This interface defines a to_string method
typedef struct {
  int (*to_string)(void* self, char* string);
} stringer_if_t;


// one more interface type
// This is to specify that type is printable
typedef struct {
  void (*display) (void* self);
} display_if_t ;


#endif
