// #include"circle.h"

#include<stdio.h>

int areaofcir(int rad);

int main()
{
    areaofcir(5);
    return 0;
}

int areaofcir(int rad)
{
    int area = 3.14*rad*rad;
    printf("area of circle : %d\n",area);
}
// int main(void)
// {
//     int radius = 5;
//     int res = areaofcir(radius);
//     printf("area of circle : %d\n",res);
//     return 0;
// }

