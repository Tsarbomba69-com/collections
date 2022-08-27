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
    u_int cap;
    Node *root;
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

    if (vec->root == NULL)
        vec->root = el;
    else
    {
        el->next = vec->root;
        vec->root = el;
    }

    vec->len += 1;
}

void *pop(Vec *vec)
{
    assert(vec != NULL && vec->len > 0);
    Node *tmp = vec->root;
    vec->root = tmp->next;
    void *result = tmp->data;
    tmp->next = NULL;
    free(tmp);
    vec->len--;
    return result;
}

Vec new_vec()
{
    Vec vec = {.len = 0, .cap = 10, .root = (Node *)malloc(10 * sizeof(Node))};
    return vec;
}

int main()
{
    Vec a = new_vec();
    printf("a = { \n\tlen: %i, \n\tcap: %i, \n\troot: %p \n}\n", a.len, a.cap, a.root);
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    while (a.len > 0)
    {
        printf("v = %i\n", (int)pop(&a));
    }
    return EXIT_SUCCESS;
}