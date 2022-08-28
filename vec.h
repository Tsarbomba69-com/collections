#pragma once
#ifndef _VEC_H_
#define _VEC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

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

Node *new_node(void *data);
void push(Vec *vec, void *data);
void enqueue(Vec *vec, void *data);
void *dequeue(Vec *vec);
void *pop(Vec *vec);
void reverse(Vec *vec);
void clear(Vec *vec);
void print_vec(Vec *vec);
void append(Vec *dest, Vec *other);
Vec new_vec();

#endif