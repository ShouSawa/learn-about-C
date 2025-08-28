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

// 複素数の定数倍
FCOMP f_mul_const(int n, FCOMP x)
{
    FCOMP res;
    BUNSU b;
    b.si = n;
    b.bo = 1;
    res.real = b_mul(b, x.real);
    res.imag = b_mul(b, x.imag);
    return res;
}

// 複素数に定数を足す
FCOMP f_add_const(int n, FCOMP x)
{
    FCOMP res;
    BUNSU b;
    b.si = n;
    b.bo = 1;
    res.real = b_add(b, x.real);
    return res;
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

//複素数3つの計算
FCOMP f_calc(FCOMP x, FCOMP y, FCOMP z)
{
    FCOMP res;
    res = f_div(f_add(f_mul(x, y), z), f_sub(x, f_mul(y, z)));
    return res;
}

//複素数1つの計算
FCOMP fcal(FCOMP x)
{
    FCOMP res;
    res = f_div(f_add_const(3, f_add(f_mul(x, x), f_mul_const(2,x))), f_add_const(-1,f_mul_const(2,x)));
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

    /*//複素数の四則演算
    c = f_add( a,b );
    printf( "(%d/%d+j%d/%d) + (%d/%d+j%d/%d) = %d/%d+j%d/%d\n",a.real.si,a.real.bo,a.imag.si,a.imag.bo,b.real.si,b.real.bo,b.imag.si,b.imag.bo,c.real.si,c.real.bo,c.imag.si,c.imag.bo);

    c = f_sub( a,b );
    printf( "(%d/%d+j%d/%d) - (%d/%d+j%d/%d) = %d/%d+j%d/%d\n",a.real.si,a.real.bo,a.imag.si,a.imag.bo,b.real.si,b.real.bo,b.imag.si,b.imag.bo,c.real.si,c.real.bo,c.imag.si,c.imag.bo);

    c = f_mul( a,b );
    printf( "(%d/%d+j%d/%d) * (%d/%d+j%d/%d) = %d/%d+j%d/%d\n",a.real.si,a.real.bo,a.imag.si,a.imag.bo,b.real.si,b.real.bo,b.imag.si,b.imag.bo,c.real.si,c.real.bo,c.imag.si,c.imag.bo);

    c = f_div( a,b );
    printf( "(%d/%d+j%d/%d) / (%d/%d+j%d/%d) = %d/%d+j%d/%d\n",a.real.si,a.real.bo,a.imag.si,a.imag.bo,b.real.si,b.real.bo,b.imag.si,b.imag.bo,c.real.si,c.real.bo,c.imag.si,c.imag.bo);
    */

    // 宿題
    c.real.si = atoi(argv[9]);
    c.real.bo = atoi(argv[10]);
    c.imag.si = atoi(argv[11]);
    c.imag.bo = atoi(argv[12]);

    d = f_calc(a, b, c);
    printf("(x*y+z)/(x-y*z) = %d/%d+j%d/%d\n", d.real.si, d.real.bo, d.imag.si, d.imag.bo);

    /*//分数の比較
    int res = b_cmp( a,b );
    if(res == 1){
    printf("aの方が大きい\n");
    }else if(res == 0){
    printf("aと等しい\n");
    }else{
    printf("aの方が小さい\n");
    }
    */

    return 0;
}

/*//過去問1main
int main( int argc, char **argv )
{
    FCOMP a,res;

    a.real.si = atoi( argv[1] );
    a.real.bo = atoi( argv[2] );
    a.imag.si = atoi( argv[3] );
    a.imag.bo = atoi( argv[4] );

    res = fcal( a );

    printf( "(%d/%d)+j(%d/%d)\n", res.real.si, res.real.bo,
				  res.imag.si, res.imag.bo );

    return 0;
}
*/