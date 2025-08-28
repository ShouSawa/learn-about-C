#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//#define NUMBER 5

struct xyz
{
    int x;
    long y;
    double z;
};

struct xyz scan_xyz()
{
    struct xyz XYZ;

    printf("int:"); scanf("%d", &XYZ.x);
    printf("long:"); scanf("%ld", &XYZ.y);
    printf("double:"); scanf("%lf", &XYZ.z);
    return XYZ;
};

int main(int argc, char **argv)
{
    struct xyz XYZ;
    XYZ = scan_xyz();

    printf("int:%d\n", XYZ.x);
    printf("long:%ld\n", XYZ.y);
    printf("double:%lf\n", XYZ.z);

    return 0;
}