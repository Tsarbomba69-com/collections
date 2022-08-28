#include "vec.h"

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