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

void print_vec(Vec *vec)
{
    assert(vec != NULL);
    Node *tmp = vec->head;
    printf("[");

    while (tmp != NULL)
    {
        printf("%p, ", tmp->data == NULL ? 0x0 : tmp->data);
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

int main()
{
    Vec a = new_vec();
    Vec b = new_vec();
    printf("a = { \n\tlen: %i, \n\thead: %p \n}\n", a.len, a.head);
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    printf("a = ");
    print_vec(&a);
    enqueue(&b, 4);
    enqueue(&b, 5);
    enqueue(&b, 6);
    printf("q = ");
    print_vec(&b);
    append(&a, &b);
    reverse(&a);
    reverse(&a);
    reverse(&a);
    printf("vec = ");
    print_vec(&a);
    clear(&a);
    while (a.len > 0)
    {
        printf("v = %i\n", (int)pop(&a));
    }

    push(&a, 9);
    printf("head->data = %i\n", (int)a.head->data);
    return EXIT_SUCCESS;
}