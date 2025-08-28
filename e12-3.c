#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define NUMBER 64

typedef struct
{
    char name[NUMBER];
    int height;
    double weight;
} Student;

Student scan_Student()
{
    Student a;

    printf("name:");
    scanf("%s", a.name);
    printf("height:");
    scanf("%d", &a.height);
    printf("weight:");
    scanf("%lf", &a.weight);
    return a;
}

int main(int argc, char **argv)
{
    Student a;
    a = scan_Student();

    printf("name:%s\n", a.name);
    printf("height:%d\n", a.height);
    printf("weight:%lf\n", a.weight);

    return 0;
}