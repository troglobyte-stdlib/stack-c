//
// file: package.h
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#ifndef MIOK_STACK_PACKAGE_H
#define MIOK_STACK_PACKAGE_H

#ifdef __cplusplus
extern "C"
{
#endif

//
// Macros to control the visibility of functions provided by this package
//
#ifdef BUILDING_MIOK_STACK_PACKAGE
#define MIOK_STACK_PUBLIC __attribute__((visibility("default")))
#else
#define MIOK_STACK_PUBLIC
#endif

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published package with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting c23 standard. If you wish to use a version of this library
// that targets an older version of C append "-support" at the end of the
// package name and everything should just work.
//

typedef struct StackOf StackOf;

MIOK_STACK_PUBLIC StackOf *miok_stack_create(void);
MIOK_STACK_PUBLIC void miok_stack_erase(StackOf **structure_ref);
MIOK_STACK_PUBLIC void miok_stack_push(StackOf *structure_ptr, const char *data);
MIOK_STACK_PUBLIC char *miok_stack_pop(StackOf *structure_ptr);
MIOK_STACK_PUBLIC char *miok_stack_peek(StackOf *structure_ptr);
MIOK_STACK_PUBLIC unsigned int miok_stack_its_empty(StackOf *structure_ptr);
MIOK_STACK_PUBLIC unsigned int miok_stack_not_empty(StackOf *structure_ptr);

#ifdef __cplusplus
}
#endif

#endif // end of MIOK_PACKAGE_H
