#include <stdio.h>
#include <stdlib.h>
#define N 256

// ファイルの出力（int）
void min_of(const int v[], int n)
{
    int res = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (res > v[i])
        {
            res = v[i];
        }
    }
    printf("%d\n", res);
}

int main(int argc, char **argv)
{
    
    FILE *fp;
    int n;
    int v[100];
    /*
    if ((fp = fopen(argv[1], "r")) == NULL) // ファイルがあるかどうか確認
    {
        perror(argv[1]);
        exit(1);
    }
    */

    /*//数字の読み込み
    int cnt = 0;
    while (fscanf(fp, "%d", &n) != EOF) // ファイル内を読み込み
    {
        v[cnt++] = n; //1文字ずつ書きこんでいる
    }
    min_of(v, cnt);
    */

    /* //文字の1文字ずつの読み込み
    int chr = 0;
    while ((chr = fgetc(fp)) != EOF) // ファイル内を読み込み
    {
        putchar(chr); // 1文字ずつ書きこんでいる
    }
    */
    //printf("\n"); 

    /*//文字の1行ずつの読み込み
    char str[N];
    while (fgets(str, N, fp) != NULL)
    {
        printf("%s", str); //1行ずつ書き込んでいる
    }
    */

    if ((fp = fopen(argv[1], "w")) == NULL) // ファイルがあるかどうか確認
    {
        perror(argv[1]);
        exit(1);
    }

    int a = 100;

    fputc('H', fp);
    fputs("Hello\n", fp);
    char data1[] = "モノづくり";
	char data2 = 'C';
	int  data3 = 2020;
    fprintf(fp, "%s %c 言語塾 %d年", data1, data2, data3);

    

    return 0;
}
