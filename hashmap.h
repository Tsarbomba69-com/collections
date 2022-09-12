#pragma once
#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// A contiguous growable HashMap type with heap-allocated contents.
typedef struct HashMap
{
    u_int len;
    struct Pair *head;
} HashMap;

typedef struct Pair
{
    int k;
    void *v;
    struct Pair *next;
} Pair;

// Inserts a key-value pair into the HashMap.
void insert_pair(HashMap *map, const char *key, void *value);
void *value(HashMap *map, const char *key);
// Creates a new empty HashMap
HashMap new_hashmap();
// Creates a new key-value pair
Pair *new_pair(const char *key, void *value);
/* Print a HashMap with a given format especifier (pass 'type' without the % symbol as it it a char).
Supported format: %p, %d, %f, %c, %x, %s, %o*/
void print_map(HashMap *map, char type);
int hash(const char *key);
#endif