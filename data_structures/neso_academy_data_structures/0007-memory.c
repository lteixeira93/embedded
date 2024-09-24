#include <stdio.h>
#include <stdlib.h>

void set_get_ptr(int *ptr, int index_s, int index_e) {
    for (size_t i = index_s; i < index_e; i++)
    {
        scanf("%d", ptr + i);
    }

    for (size_t i = 0; i < index_e; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int *ptr = (int*)malloc(2*sizeof(int));

    if (ptr == NULL) exit(1);    
    set_get_ptr(ptr, 0, 2);      

    ptr = (int*)realloc(ptr, 4*sizeof(int));

    set_get_ptr(ptr, 2, 4);

    printf("%p\n", ptr);
    
    free(ptr);
    ptr = NULL;

    printf("%p\n", ptr);

    return 0;
}
