#pragma once
#ifndef _VEC_H_
#define _VEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

// Heap allocated list node (element).
typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

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
// Push a element to the beggining of the list.
void push(Vec *vec, void *data);
// Push a element to the end of the list.
void enqueue(Vec *vec, void *data);
// Remove and return the last element of the list.
void *dequeue(Vec *vec);
// Remove and return the first element of the list.
void *pop(Vec *vec);
// Reverse the order of a list.
void reverse(Vec *vec);
// Deallocate all of the list data.
void clear(Vec *vec);
/* Print a list with a given format especifier (pass 'type' without the % symbol as it it a char). 
Supported format: %p, %d, %f, %c, %x, %s, %o*/
void print_vec(Vec *vec, char type);
void append(Vec *dest, Vec *other);
Vec new_vec();

#endif