#include "hashmap.h"

Pair *new_pair(const char *key, void *value)
{
    Pair *node = (Pair *)malloc(sizeof(Pair));
    assert(node != NULL);
    int h_key = hash(key);
    node->v = value;
    node->k = h_key;
    node->next = NULL;
    return node;
}

void *insert_pair(HashMap *map, const char *key, void *value)
{
    assert(map != NULL);
    Pair *el = new_pair(key, value);

    if (map->head == NULL)
    {
        map->head = el;
        map->len++;
        return NULL;
    }

    for (Pair *cursor = map->head; cursor != NULL; cursor = cursor->next)
    {
        if (cursor->k == el->k)
        {
            void *result = cursor->v;
            cursor->v = value;
            map->len++;
            return result;
        }
    }

    el->next = map->head;
    map->head = el;
    map->len += 1;
    return NULL;
}

void print_map(HashMap *map)
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
        while (tmp != NULL)
        {
            switch (map->type)
            {
            case INT:
                printf("%d", (int)tmp->v);
                break;
            case FLOAT:
                printf("%f", *((float *)tmp->v));
                break;
            case CHAR:
                printf("\'%c\'", (char)tmp->v);
                break;
            case STRING:
                printf("\"%s\"", (char *)tmp->v);
                break;
            case BOOL:
                printf("%s", tmp->v ? "true" : "false");
                break;
            default:
                fprintf(stderr, "Unsupported format especifier.\nAllowed formats: INT, FLOAT, CHAR, STRING, BOOL\n");
                exit(EXIT_FAILURE);
            }
            tmp = tmp->next;
            if (tmp != NULL)
                printf(", ");
        }
    }

    puts("]");
}

void *value(HashMap *map, const char *key)
{
    assert(map != NULL && map->len > 0);
    int h_key = hash(key);

    for (Pair *cursor = map->head; cursor != NULL; cursor = cursor->next)
    {
        if (cursor->k == h_key)
            return cursor->v;
    }

    return NULL;
}

HashMap new_hashmap(Type type)
{
    HashMap map = {.len = 0, .head = NULL, .type = type};
    return map;
}

int hash(const char *key)
{
    int hash1 = 5381;
    int hash2 = hash1;
    int c;
    char *s = key;

    while ((c = s[0]) != 0)
    {
        hash1 = ((hash1 << 5) + hash1) ^ c;
        c = s[1];
        if (c == 0)
            break;
        hash2 = ((hash2 << 5) + hash2) ^ c;
        s += 2;
    }

    return hash1 + (hash2 * 1566083941);
}
