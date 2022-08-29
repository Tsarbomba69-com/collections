#include "vec.h"

Node *new_node(void *data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Vec *vec, void *data)
{
    Node *el = new_node(data);
    assert(el != NULL && vec != NULL);

    if (vec->head == NULL)
        vec->head = el;
    else
    {
        el->next = vec->head;
        vec->head = el;
    }

    vec->len += 1;
}

void enqueue(Vec *vec, void *data)
{
    Node *el = new_node(data);
    assert(el != NULL && vec != NULL);

    if (vec->head == NULL)
        vec->head = el;
    else
    {
        Node *cursor = vec->head;
        while (cursor != NULL)
        {
            if (cursor->next == NULL)
            {
                cursor->next = el;
                el->next = NULL;
            }

            cursor = cursor->next;
        }
    }
    vec->len++;
}

void *dequeue(Vec *vec)
{
    assert(vec != NULL && vec->len > 0);

    Node *cursor = vec->head;
    while (cursor != NULL)
    {
        if (cursor->next == NULL)
        {
            void *result = cursor->data;
            free(cursor);
            vec->len--;
            return result;
        }

        cursor = cursor->next;
    }
}

void *pop(Vec *vec)
{
    assert(vec != NULL && vec->len > 0);
    Node *tmp = vec->head;
    vec->head = tmp->next;
    void *result = tmp->data;
    free(tmp);
    vec->len--;
    return result;
}

void reverse(Vec *vec)
{
    assert(vec != NULL);
    Node *prev = NULL;
    Node *current = vec->head;

    while (current != NULL)
    {
        Node *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    vec->head = prev;
}

void clear(Vec *vec)
{
    assert(vec != NULL);

    Node *current = vec->head;

    while (current != NULL)
    {
        Node *tmp = current;
        current = current->next;
        free(tmp);
    }

    vec->len = 0;
}

void print_vec(Vec *vec, char type)
{
    assert(vec != NULL);
    Node *tmp = vec->head;
    printf("[");

    while (tmp != NULL)
    {
        switch (type)
        {
        case 'p':
            printf("%p, ", tmp->data);
            break;
        case 'd':
            printf("%d, ", (int)tmp->data);
            break;
        case 'f':
            printf("%f, ", tmp->data);
            break;
        case 'c':
            printf("%c, ", (char)tmp->data);
            break;
        case 'x':
            printf("%x, ", (u_int)tmp->data);
            break;
        case 'o':
            printf("%o, ", (u_int)tmp->data);
            break;
        case 's':
            printf("%s, ", (char *)tmp->data);
            break;
        default:
            fprintf(stderr, "Unsupported format especifier %c.\nAllowed formats: p, d, f, c, x, s, o\n", type);
            exit(EXIT_FAILURE);
        }
        tmp = tmp->next;
    }

    puts("]");
}

void append(Vec *dest, Vec *other)
{
    assert(dest != NULL && other != NULL && other->len > 0);

    while (other->len > 0)
    {
        enqueue(dest, pop(other));
    }
}

Vec new_vec()
{
    Vec vec = {.len = 0, .head = (Node *)malloc(10 * sizeof(Node))};
    vec.head = NULL;
    return vec;
}