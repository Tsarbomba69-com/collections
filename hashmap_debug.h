// #include "vec.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A contiguous growable array type with heap-allocated contents.
typedef struct HashMap
{
    u_int len;
    struct Pair *head;
} HashMap;

typedef struct Pair
{
    char *k;
    void *v;
    struct Pair *next;
} Pair;

Pair *new_pair(const char *key, void *value)
{
    Pair *node = (Pair *)malloc(sizeof(Pair));
    assert(node != NULL);
    // uint8_t in[64], out[16];
    // siphash(in, 64, key, out, 16); // FIX: Create a pure siphash function
    node->v = value;
    node->k = (char *)malloc(strlen(key));
    strcpy(node->k, key);
    node->next = NULL;
    return node;
}

void insert_pair(HashMap *map, const char *key, void *value)
{
    assert(map != NULL);
    Pair *el = new_pair(key, value);

    if (map->head == NULL)
        map->head = el;
    else
    {
        el->next = map->head;
        map->head = el;
    }

    map->len += 1;
}

void print_map(HashMap *map, char type)
{
    assert(map != NULL);
    if (map->len == 0)
    {
        puts("[]");
        return;
    }

    Pair *tmp = map->head;
    printf("[");

    while (tmp != NULL)
    {
        switch (type)
        {
        case 'p':
            printf("%p, ", tmp->v);
            break;
        case 'd':
            printf("%d, ", (int)tmp->v);
            break;
        case 'f':
            printf("%f, ", tmp->v);
            break;
        case 'c':
            printf("%c, ", (char)tmp->v);
            break;
        case 'x':
            printf("%x, ", (u_int)tmp->v);
            break;
        case 'o':
            printf("%o, ", (u_int)tmp->v);
            break;
        case 's':
            printf("%s, ", (char *)tmp->v);
            break;
        default:
            fprintf(stderr, "Unsupported format especifier %c.\nAllowed formats: p, d, f, c, x, s, o\n", type);
            exit(EXIT_FAILURE);
        }
        tmp = tmp->next;
    }

    puts("]");
}

void *value(HashMap *map, const char *key)
{
    assert(map != NULL && map->len > 0);
    // uint8_t in[64], out[16];
    // siphash(in, 64, key, out, 16);

    for (Pair *cursor = map->head; cursor != NULL; cursor = cursor->next)
    {
        if (strcmp(cursor->k, key) == 0)
            return cursor->v;
    }

    return NULL;
}

HashMap new_hashmap()
{
    HashMap map = {.len = 0, .head = (Pair *)malloc(sizeof(Pair))};
    map.head = NULL;
    return map;
}
