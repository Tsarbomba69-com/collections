#include "vec.h"
// #include "vec_debug.h"

int main()
{
    Vec a = new_vec();
    Vec b = new_vec();
    printf("a = { \n\tlen: %i, \n\thead: %p \n}\n", a.len, a.head);
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    printf("a = ");
    print_vec(&a, 'd');
    enqueue(&b, 4);
    enqueue(&b, 5);
    enqueue(&b, 6);
    printf("b = ");
    print_vec(&b, 'p');
    append(&a, &b);
    reverse(&a);
    reverse(&a);
    reverse(&a);
    printf("a = ");
    print_vec(&a, 'd');
    Vec c = clone(&a);
    insert(&c, 69, 6);
    insert(&c, 69, 0);
    printf("c[0] = %i\n", vec_remove(&c, 0));
    printf("c[0] = %i\n", vec_remove(&c, 0));
    truncate(&c, 5); // original = [5, 4, 1, 2, 3, 69]
    printf("clone = ");
    print_vec(&c, 'd');
    printf("value = %i\n", get(&a, 1));
    clear(&a);
    while (a.len > 0)
    {
        printf("v = %i\n", (int)pop(&a));
    }

    push(&a, 9);
    printf("head->data = %i\n", (int)a.head->data);
    return EXIT_SUCCESS;
}