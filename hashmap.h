#pragma once
#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "vec.h"

// A contiguous growable HashMap type with heap-allocated contents.
typedef struct HashMap
{
    u_int len;
    Type type;
    struct Pair *head;
} HashMap;

typedef struct Pair
{
    int k;
    void *v;
    struct Pair *next;
} Pair;

// Inserts a key-value pair into the map.
// If the map did not have this key present, NULL is returned.
// If the map did have this key present, the value is updated, and the old value is returned. The key is not updated
void *insert_pair(HashMap *map, const char *key, void *value);
void *value(HashMap *map, const char *key);
// Creates a new empty HashMap
HashMap new_hashmap(Type type);
// Creates a new key-value pair
Pair *new_pair(const char *key, void *value);
/* Print a hashmap with a given format especifier.
Supported format: INT, FLOAT, CHAR, STRING, BOOL*/
void print_map(HashMap *map);
int hash(const char *key);
#endif