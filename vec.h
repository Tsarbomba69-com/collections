#pragma once
#ifndef _VEC_H_
#define _VEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Heap allocated vector node (element).
typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

// vector struct
typedef struct Vec
{
    u_int len;
    Node *head;
} Vec;

//--------------------------------------
// TODO: Move to a different file
typedef void *Ok;

typedef struct Result
{
    Ok data;
    char error[];
} Result;
//--------------------------------------

// Creates a new node containig the given data.
Node *new_node(void *data);
// Push a element to the beggining of the vector.
void push(Vec *vec, void *data);
// Push a element to the end of the vector.
void enqueue(Vec *vec, void *data);
// Remove and return the last element of the vector.
void *dequeue(Vec *vec);
// Remove and return the first element of the vector.
void *pop(Vec *vec);
// Reverse the order of a vector.
void reverse(Vec *vec);
// Deallocate all of the vector data.
void clear(Vec *vec);
/* Print a vector with a given format especifier (pass 'type' without the % symbol as it it a char).
Supported format: %p, %d, %f, %c, %x, %s, %o*/
void print_vec(Vec *vec, char type);
// Append 'other' vector to 'dest' vector.
void append(Vec *dest, Vec *other);
// Get an element from the vector with a given index.
void *get(Vec *vec, size_t index);
// Clone a vector.
Vec clone(Vec *vec);
// Inserts an element at position index within the vector, shifting all elements after it to the right.
void insert(Vec *vec, void *data, size_t index);
// Removes and returns the element at position index within the vector, shifting all elements after it to the left.
void *vec_remove(Vec *vec, size_t index);
// Shortens the vector, keeping the first len elements and dropping the rest.
void truncate(Vec *vec, size_t len);
// Creates a new empty vector
Vec new_vec();

#endif