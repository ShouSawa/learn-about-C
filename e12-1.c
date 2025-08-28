#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define NAME_LEN 64

struct student
{
    char name[NAME_LEN];
    int height;
    double weight;
};

int main(int argc, char **argv)
{
    struct student takao = {"Takao", 173};

    printf("氏名=%s\n", takao.name);
    printf("氏名のアドレス: %p\n", &takao.name);
    printf("身長=%d\n", takao.height);
    printf("身長のアドレス: %p\n", &takao.height);
    printf("体重=%.1f\n", takao.weight);
    printf("体重のアドレス: %p\n", &takao.weight);

    return 0;
}