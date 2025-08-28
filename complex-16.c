#include <stdio.h>
#include <stdlib.h>

typedef struct bun {
    int si;  /* 分子 */
    int bo;  /* 分母 */
} BUNSU;

typedef struct fcomp {
    BUNSU real; /* 実部 */
    BUNSU imag; /* 虚部 */
} FCOMP;

#define abs(x) x < 0 ? -x : x // 絶対値

// 分数の2乗
BUNSU square(BUNSU a)
{
    BUNSU res;
    res.si = a.si * a.si;
    res.bo = a.bo * a.bo;
    return res;
}

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
    res.si = x.si * y.bo - y.si * x.bo;
    res.bo = x.bo * y.bo;
    return approx(res);
}

// 分数のかけ算
BUNSU b_mul(BUNSU x, BUNSU y)
{
    BUNSU res;
    res.si = x.si * y.si;
    res.bo = x.bo * y.bo;
    return approx(res);
}

// 分数の割り算
BUNSU b_div(BUNSU x, BUNSU y)
{
    BUNSU res;
    res.si = x.si * y.bo;
    res.bo = x.bo * y.si;
    return approx(res);
}

// 分数の比較
int b_cmp(BUNSU x, BUNSU y)
{
    BUNSU res = b_sub(x, y);
    if (res.si > 0)
    {
        return 1;
    }
    else if (res.si == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

// 複素数の足し算
FCOMP f_add(FCOMP x, FCOMP y)
{
    FCOMP res;
    res.real = b_add(x.real, y.real);
    res.imag = b_add(x.imag, y.imag);
    return res;
}

// 複素数の引き算
FCOMP f_sub(FCOMP x, FCOMP y)
{
    FCOMP res;
    res.real = b_sub(x.real, y.real);
    res.imag = b_sub(x.imag, y.imag);
    return res;
}

// 複素数の掛け算
FCOMP f_mul(FCOMP x, FCOMP y)
{
    FCOMP res;
    res.real = b_sub(b_mul(x.real, y.real), b_mul(x.imag, y.imag));
    res.imag = b_add(b_mul(x.imag, y.real), b_mul(x.real, y.imag));
    return res;
}

// 複素数の割り算
FCOMP f_div(FCOMP x, FCOMP y)
{
    FCOMP res;
    BUNSU b;
    b = b_add(square(y.real), square(y.imag));
    res.real = b_div(b_add(b_mul(x.real, y.real), b_mul(x.imag, y.imag)), b);
    res.imag = b_div(b_sub(b_mul(x.imag, y.real), b_mul(x.real, y.imag)), b);
    return res;
}

int main(int argc, char **argv)
{
    FCOMP a, b, c, d;

    a.real.si = atoi(argv[1]);
    a.real.bo = atoi(argv[2]);
    a.imag.si = atoi(argv[3]);
    a.imag.bo = atoi(argv[4]);
    b.real.si = atoi(argv[5]);
    b.real.bo = atoi(argv[6]);
    b.imag.si = atoi(argv[7]);
    b.imag.bo = atoi(argv[8]);
    c.real.si = atoi(argv[9]);
    c.real.bo = atoi(argv[10]);
    c.imag.si = atoi(argv[11]);
    c.imag.bo = atoi(argv[12]);

    d = f_div(f_add(f_mul(a, b), c), f_sub(a, f_mul(b, c)));
    printf("(x*y+z)/(x-y*z) = %d/%d+j%d/%d\n", d.real.si, d.real.bo, d.imag.si, d.imag.bo);


    return 0;
}