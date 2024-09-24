#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

struct point* allocate_structure(int x, int y)
{
    struct point *ptr = (struct point*)malloc(sizeof(struct point*));
    ptr->x = x;
    ptr->y = y;

    return ptr;
}   

void display_values(const struct point *ptr) 
{
    printf("X = %d | Y = %d\n", ptr->x, ptr->y);
}


int main(void)
{
    struct point *ptr = allocate_structure(2, 3);
    
    display_values(ptr);

    free(ptr);
    ptr = NULL;
    
    return 0;
}
