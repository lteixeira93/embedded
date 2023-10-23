#include <stdio.h>

struct pack
{
    unsigned int        :3; // Padding
    unsigned int f1     :1;
    unsigned int f2     :1;
    unsigned int f3     :1;

    unsigned int type   :8;
    unsigned int index  :18;
};

int main(int argc, char const *argv[])
{
    struct pack packed_data;

    packed_data.type = 7;

    return 0;
}
