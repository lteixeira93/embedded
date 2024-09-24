#include <stdio.h>

void change_element(int arr[][3]);
void print_matrix(const int arr[][3]);
void swap(int x, int y);

int main(int argc, char const *argv[])
{
    int arr[4][3] = {{1,2,3}, {2,4,6}, {3,6,9}, {4,8,12}};

    print_matrix(arr);
    change_element(arr);
    print_matrix(arr);
    
    return 0;
}

void change_element(int arr[][3])
{
      for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            arr[0][j] = arr[2][i];
        }   
    }
}

void print_matrix(const int arr[][3]) 
{
    for (size_t i = 0; i < 4; i++)
    {
        printf("{");
        for (size_t j = 0; j < 3; j++)
        {
            printf(" %d ", arr[i][j]);
        }   
        printf("} ");
    }
    printf("\n");
}