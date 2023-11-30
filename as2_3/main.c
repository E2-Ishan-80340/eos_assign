// 3. Create a multi-ﬁle project (main.c, circle.c/.h, square.c/.h, rectangle.c/.h). +
// Compile the program using "gcc" and execute it. No fork(), exec() expected here.

#include"circle.h"
#include"rectangle.h"
#include"square.h"

int main(void)
{
    int len = 5;
    int bre = 5;
    int side = 5;
    int radius = 5;
    int res1 = areaofcir(radius);
    printf("area of circle : %d\n",res1);
    int res2 = arofsquare(side);
    printf("area of sqaure : %d\n",res2);
    int res3 = arofrect(len,bre);
    printf("area of rectangle : %d\n",res3);
    return 0;
}