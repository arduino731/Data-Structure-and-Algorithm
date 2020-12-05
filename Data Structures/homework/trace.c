#include <stdio.h>
typedef struct {
 int x;
 int y;
} fractionT;

int func(fractionT *a, int *b, int **c)
{
 int x=8, y=13;
 *b = y % x / 2;
 a++;
 a->y = 25;
 **c = 17;
 return a->y + y;
}

int main()
{
int z[6] = {3, 4, 5, 7, 2, 9};
 int *p1, **p2;
 fractionT f[2];
 p1 = &z[2];
 p2 = &p1;
 *p1++ = 12;
 *++p1 = 15;
 printf("%d %d %d %d \n", z[2], z[3], z[4], **p2);

 z[3] = func(&f[0], &f[0].y, p2);
 printf("%d %d %d %d \n", z[3], z[4], f[0].y, f[1].y);
}


