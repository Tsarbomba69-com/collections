#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct Vec
{
    /* data */
    u_int len;
    u_int cap;
    Node *root;
} Vec;

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

    if (vec->len == 0)
        vec->root = el;
    else
    {
        for (Node *cursor = vec->root; cursor != NULL; cursor = cursor->next)
        {
            if (cursor->next == NULL)
            {
                cursor->next = el;
                el->next = NULL;
            }
        }
    }

    vec->len += 1;
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
    push(&a, 20);
    push(&a, 10);
    push(&a, 30);
    printf("v[0] = %i\n", (u_int)a.root->data);
    printf("v[1] = %i\n", (u_int)a.root->next->data);
    printf("v[2] = %i\n", (u_int)a.root->next->next->data);
    return 0;
}