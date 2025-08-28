#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
// #define NUMBER 5
// #define sqr(n)    ((n) * (n))

typedef struct
{           // 分数
    int si; // 分子
    int bo; // 分母
} BUNSU;

// 最大公約数
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

// 約分
BUNSU approx(BUNSU a)
{
    BUNSU approx;
    int g = gcd(a.si, a.bo);
    approx.si = a.si / g;
    approx.bo = a.bo / g;
    if (approx.bo < 0)
    { // 分母は必ず正にする
        approx.bo = abs(approx.bo);
        approx.si *= -1;
    }
    return approx;
}

// 分数の足し算
BUNSU b_add(BUNSU x, BUNSU y)
{
    BUNSU res;
    res.si = x.si * y.bo + y.si * x.bo;
    res.bo = x.bo * y.bo;
    return approx(res);
}

// 分数の引き算
BUNSU b_sub(BUNSU x, BUNSU y)
{
    BUNSU res;
    y.si = -y.si;
    res = b_add(x, y);
    return approx(res);
}

// 分数のスワップ
void b_swap(BUNSU *a, BUNSU *b)
{
    BUNSU temp = *a;
    *a = *b;
    *b = temp;
}

// 分数の配列のソート
void b_sort(BUNSU bunsu[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (b_sub(bunsu[j], bunsu[j+1]).si < 0)
            {
                b_swap(&bunsu[j], &bunsu[j+1]);
            }
        }
    }
}

int main(int argc, char **argv)
{
    BUNSU bunsu[100];
    for (int i = 0; i < (argc - 1) / 2; i++)
    {
        bunsu[i].si = atoi(argv[i * 2 + 1]);
        bunsu[i].bo = atoi(argv[i * 2 + 2]);
    }

    for (int i = 0; i < (argc - 1) / 2; i++)
    {
        printf("%d/%d\n", bunsu[i].si, bunsu[i].bo);
    }

    b_sort(bunsu, (argc - 1) / 2);

    printf("\n");
    for (int i = 0; i < (argc - 1) / 2; i++)
    {
        printf("%d/%d\n", bunsu[i].si, bunsu[i].bo);
    }

    return 0;
}
