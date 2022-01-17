//
// file: package.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#include "miok/stack.h"

#include <stdlib.h>
#include <string.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Miok Libraries
// 'StackNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_next_ptr] is the pointer to the next node
//
typedef struct StackNode
{
    char *_data;
    struct StackNode *_next_ptr;
} StackNode; // end of struct

//
// This is the official definition for the Miok Libraries
// 'StackOf' type.
//
// Members:
// > _top_ptr is the pointer to top of stack
//
struct StackOf
{
    size_t _size;
    struct StackNode *_top_ptr;
}; // end of struct

//
// Should return a newly hatched data structure object if
// it pass the not nullptr test. But if it was a bad egg
// we just return nullptr.
//
// Param list:
// -> There is none to speak of at this time.
//
StackOf *miok_stack_create(void)
{
    StackOf *new_structure = malloc(sizeof(*new_structure));
    if (!new_structure)
    {
        return NULL;
    } // end if
    new_structure->_size = 0;
    new_structure->_top_ptr = NULL;

    return new_structure;
} // end of function miok_stack_create

//
// Should erase the stack structure if it’s not nullptr else
// do nothing.
//
// Param list:
// -> [structure_ref]: Reference pointer to your structure
//
void miok_stack_erase(StackOf **structure_ref)
{
    if (!*structure_ref)
    {
        return;
    } // end if

    StackOf *temp_structure = *structure_ref;

    while (!miok_stack_its_empty(temp_structure))
    {
        miok_stack_pop(temp_structure);
    } // end while

    free(temp_structure);
    temp_structure = NULL;
    *structure_ref = NULL;
} // end of function miok_stack_erase

//
// Should push a new recored into the stack if the
// structure is not nullptr. Else nothing.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void miok_stack_push(StackOf *structure_ptr, const char *data)
{
    if (!structure_ptr)
    {
        return;
    } // end if

    StackNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if

    temp->_data = (char *)data;
    temp->_next_ptr = structure_ptr->_top_ptr;
    structure_ptr->_top_ptr = temp;
    ++structure_ptr->_size;
} // end of function miok_stack_push

//
// Should return the value stored in the removed node from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_stack_pop(StackOf *structure_ptr)
{
    if (!structure_ptr->_top_ptr)
    {
        return NULL;
    } // end if

    StackNode *temp = structure_ptr->_top_ptr;
    char *popped = structure_ptr->_top_ptr->_data;
    structure_ptr->_top_ptr = structure_ptr->_top_ptr->_next_ptr;

    temp->_data = 0;
    temp->_next_ptr = NULL;
    --structure_ptr->_size;

    free(temp);
    temp = NULL;
    return popped;
} // end of function miok_stack_pop

//
// Should return the value stored in begin pointer from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
char *miok_stack_peek(StackOf *structure_ptr)
{
    return (structure_ptr->_top_ptr) ? structure_ptr->_top_ptr->_data : NULL;
} // end of function miok_stack_peek

//
// Should return a success value if the structure is an
// empty structure.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_stack_its_empty(StackOf *structure_ptr)
{
    return (!structure_ptr->_top_ptr) ? success : failed;
} // end of function miok_stack_its_empty

//
// Should return a success value if the structure is not
// an empty structure.
//
// Param list:
// -> [structure_ptr]: Pointer to your structure
//
unsigned int miok_stack_not_empty(StackOf *structure_ptr)
{
    return (structure_ptr->_top_ptr) ? success : failed;
} // end of function miok_stack_not_empty