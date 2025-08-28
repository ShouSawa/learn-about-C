#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    char furi[100];
    int koku;
    int san;
    int rika;
    int shakai;
    int total;
} STUDENT;

void sort(STUDENT class[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (class[j].total < class[j+1].total)
            {
                STUDENT temp = class[j];
                class[j] = class[j+1];
                class[j+1] = temp;
            }
            else if(class[j].total == class[j+1].total)
            {
                //文字数の少ない方の長さを見る
                int len = strlen(class[j].furi) < strlen(class[j+1].furi) ? strlen(class[j].furi) : strlen(class[j+1].furi);
                //同じ文字じゃなくなるまで，１文字ずつ比較
                for(int k = 0; k < len; k++){
                    if (strncmp(class[j].furi, class[j+1].furi, k) > 0){
                        STUDENT temp = class[j];
                        class[j] = class[j+1];
                        class[j+1] = temp;
                        break;
                    }
                }
            }
        }
    }
}

/*  Ver.2
void sort(STUDENT class[], int n)
{
for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (class[i].total < class[j].total)
            {
                STUDENT temp = class[i];
                class[i] = class[j];
                class[j] = temp;
            }
            else if(class[i].total == class[j].total)
            {
                //文字数の少ない方の長さを見る
                int len = strlen(class[i].furi) < strlen(class[j].furi) ? strlen(class[i].furi) : strlen(class[j].furi);
                //同じ文字じゃなくなるまで，１文字ずつ比較
                for(int k = 0; k < len; k++){
                    if (strncmp(class[i].furi, class[j].furi, k) > 0){
                        STUDENT temp = class[i];
                        class[i] = class[j];
                        class[j] = temp;
                        break;
                    }
                }
            }
        }
    }
}
    */

int main(int argc, char **argv)
{
    STUDENT class[50];
    FILE *fp;
    int i, j;

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        exit(1);
    }

    i = 0;
    while (fscanf(fp, "%s%s%d%d%d%d", class[i].name, class[i].furi, &(class[i].koku), &(class[i].san), &(class[i].rika), &(class[i].shakai)) != EOF)
    {
        i++;
    }

    j = 0;
    while (j < i)
    {
        class[j].total = class[j].koku + class[j].san + class[j].rika + class[j].shakai;
        j++;
    }

    sort(class, i);

    printf("%-10s %-25s %8s %8s %8s %8s %8s\n", "氏名", "ふりがな", "国語", "算数", "理科", "社会", "合計");
    j = 0;
    while (j < i)
    {
        printf("%-10s %-30s %6d %6d %6d %6d %6d\n", class[j].name, class[j].furi, class[j].koku, class[j].san, class[j].rika, class[j].shakai, class[j].total);
        j++;
    }

    return (0);
}
