#include <stdio.h>

int sum(int num) {
    static int sum;
    sum += num;
    return sum;
}

int main(int argc, char const *argv[]) {
    printf("%d\n", sum(25));
    printf("%d\n", sum(15));
    printf("%d\n", sum(30));

    return 0;
}
