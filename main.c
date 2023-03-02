#include "vec.h"
#include "hashmap.h"
// #include "hashmap_debug.h"
// #include "vec_debug.h"

int main()
{
    Vec a = new_vec(INT);
    Vec b = new_vec(INT);
    HashMap map = new_hashmap(STRING);
    printf("f1 = %s\n", insert_pair(&map, "First Name", "Hendrick"));
    printf("f2 = %s\n", insert_pair(&map, "Middle Name", "Walter"));
    printf("f3 = %s\n", insert_pair(&map, "Last Name", "Almeida"));
    printf("f4 = %s\n", insert_pair(&map, "Last Name", "Dias"));
    printf("map = ");
    print_map(&map);
    printf("v = %s\n", value(&map, "Last Name"));
    printf("a = { \n\tlen: %i, \n\thead: %p \n}\n", a.len, a.head);
    push(&a, (T)1);
    push(&a, (T)2);
    push(&a, (T)3);
    printf("a = ");
    print_vec(&a);
    enqueue(&b, (T)4);
    enqueue(&b, (T)5);
    enqueue(&b, (T)6);
    printf("b = ");
    print_vec(&b);
    append(&a, &b);
    reverse(&a);
    reverse(&a);
    reverse(&a);
    printf("a = ");
    print_vec(&a);
    Vec c = clone(&a);
    insert(&c, (T)69, 6);
    insert(&c, (T)69, 0);
    insert(&c, (T)'9', 0);
    print_vec(&c);
    printf("c[0] = %i\n", vec_remove(&c, 0));
    printf("c[0] = %i\n", vec_remove(&c, 0));
    truncate(&c, 5); // original = [5, 4, 1, 2, 3, 69]
    printf("clone = ");
    print_vec(&c);
    printf("value = %i\n", get(&a, 1));
    clear(&a);
    while (a.len > 0)
    {
        printf("v = %i\n", pop(&a));
    }

    push(&a, (T)9);
    printf("head->data = %i\n", a.head->data);
    char array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    Vec d = new_vec(CHAR);
    VEC(d, array, sizeof array);
    float f_array[] = {3.14, 1.0, 5.5, 180.0, 360.6, 11.11, 12.0, 666};
    Vec f = new_vec(FLOAT);
    VEC(f, f_array, 8);
    printf("d = ");
    print_vec(&d);
    printf("f = ");
    print_vec(&f);
    return EXIT_SUCCESS;
}