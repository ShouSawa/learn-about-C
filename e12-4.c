#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define NUMBER 5
#define NAME_LEN 64

typedef struct
{
    char name[NAME_LEN];
    int height;
    double weight;
} Student;

void swap_Student(Student *x, Student *y)
{
    Student temp = *x;
    *x = *y;
    *y = temp;
}

void sort_by_height(Student a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (a[j - 1].height > a[j].height)
            {
                swap_Student(&a[j - 1], &a[j]);
            }
        }
    }
}

void sort_by_name(Student a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            for (int k = 0; k < NAME_LEN; k++)
            {
                if (a[j - 1].name[k] > a[j].name[k])
                {   
                    swap_Student(&a[j - 1], &a[j]);
                    break;
                }else if (a[j - 1].name[k] < a[j].name[k]){
                    break;
                }
            }
        }
    }
}

int main(int argc, char **argv)
{

    Student std[] = {
        {"Sato", 178, 61.2},
        {"Sanaka", 175, 62.5},
        {"Takao", 173, 86.2},
        {"Mike", 165, 72.3},
        {"Masaki", 179, 77.5}};

    /*
    Student std[5];
    for(int i = 0; i < 5; i++){
        printf("name:");
        scanf("%s", std[i].name);
        printf("height:");
        scanf("%d", &std[i].height);
        printf("weight:");
        scanf("%lf", &std[i].weight);
    }
    */

    for (int i = 0; i < NUMBER; i++)
    {
        printf("%-8s %6d%6.1f\n", std[i].name, std[i].height, std[i].weight);
    }

    int i = 0;
    printf("\n身長，名前どちらでソートする？（身長[1]，名前[2]）:");
    scanf("%d", &i);

    if (i == 1)
    {
        sort_by_height(std, NUMBER);
        puts("身長順にソートしました．");
    }
    else
    {
        sort_by_name(std, NUMBER);
        puts("名前順にソートしました．");
        
    }

    for (int i = 0; i < NUMBER; i++)
    {
        printf("%-8s %6d%6.1f\n", std[i].name, std[i].height, std[i].weight);
    }

    return 0;
}
