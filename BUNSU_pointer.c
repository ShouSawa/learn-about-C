#include <stdio.h>
#include <stdlib.h>
#define int long long
#define signed int
typedef struct
{
    int si;
    int bo;
} BUNSU;
typedef struct
{
    BUNSU real;
    BUNSU imag;
} FCOMP;
signed gcd(int a, int b)
{
    return ((a % b) == 0) ? b : gcd(b, (a % b));
}
signed yakubun(BUNSU *x)
{
    if (x->si != 0)
    {
        int yaku = abs(gcd(x->si, x->bo));
        x->si /= yaku;
        x->bo /= yaku;
    }
    else
    {
        x->bo = 1;
    }
}
void mp(BUNSU *x)
{
    if (x->si < 0 && x->bo < 0)
    {
        x->si *= -1;
        x->bo *= -1;
    }
    else if (x->bo < 0)
    {
        x->si *= -1;
        x->bo *= -1;
    }
}
BUNSU add(BUNSU *x, BUNSU *y)
{
    BUNSU result;
    result.si = (x->si * y->bo) + (x->bo * y->si);
    result.bo = (x->bo * y->bo);
    yakubun(&result);
    mp(&result);
    return result;
}
FCOMP f_add(FCOMP *x, FCOMP *y)
{
    FCOMP res;
    res.real = add(&(x->real), &(y->real));
    res.imag = add(&(x->imag), &(y->imag));
    return res;
}
BUNSU sub(BUNSU *x, BUNSU *y)
{
    BUNSU result;
    result.si = (x->si * y->bo) - (x->bo * y->si);
    result.bo = (x->bo * y->bo);
    yakubun(&result);
    mp(&result);
    return result;
}
FCOMP f_sub(FCOMP *x, FCOMP *y)
{
    FCOMP res;
    res.real = sub(&(x->real), &(y->real));
    res.imag = sub(&(x->imag), &(y->imag));
    return res;
}
BUNSU mul(BUNSU *x, BUNSU *y)
{
    BUNSU result;
    result.si = (x->si * y->si);
    result.bo = (x->bo * y->bo);
    yakubun(&result);
    mp(&result);
    return result;
}
FCOMP f_mul(FCOMP *x, FCOMP *y)
{
    FCOMP res;
    BUNSU a = mul(&(x->real), &(y->real));
    BUNSU b = mul(&(x->imag), &(y->imag));
    res.real = (sub(&a, &b));
    a = mul(&(x->real), &(y->imag));
    b = mul(&(x->imag), &(y->real));
    res.imag = (add(&a, &b));
    return res;
}
BUNSU s_div(BUNSU *x, BUNSU *y)
{
    BUNSU result;
    result.si = (x->si * y->bo);
    result.bo = (x->bo * y->si);
    yakubun(&result);
    mp(&result);
    return result;
}
FCOMP f_div(FCOMP *x, FCOMP *y)
{
    FCOMP res;
    BUNSU a = mul(&(x->real), &(y->real));
    BUNSU b = mul(&(x->imag), &(y->imag));
    BUNSU c = add(&a, &b);
    a = mul(&(y->real), &(y->real));
    b = mul(&(y->imag), &(y->imag));
    BUNSU d = add(&a, &b);
    res.real = s_div(&c, &d);
    a = mul(&(x->real), &(y->imag));
    b = mul(&(x->imag), &(y->real));
    c = sub(&b, &a);
    res.imag = s_div(&c, &d);
    return res;
}
int main(int argc, char **argv)
{
    FCOMP x, y, z,c;
    x.real.si = atoll(argv[1]);
    x.real.bo = atoll(argv[2]);
    x.imag.si = atoll(argv[3]);
    x.imag.bo = atoll(argv[4]);
    y.real.si = atoll(argv[5]);
    y.real.bo = atoll(argv[6]);
    y.imag.si = atoll(argv[7]);
    y.imag.bo = atoll(argv[8]);
    z.real.si = atoll(argv[9]);
    z.real.bo = atoll(argv[10]);
    z.imag.si = atoll(argv[11]);
    z.imag.bo = atoll(argv[12]);

//複素数の四則演算
    c = f_add( &x,&y );
    printf( "(%d/%d+j%d/%d) + (%d/%d+j%d/%d) = %d/%d+j%d/%d\n",x.real.si,x.real.bo,x.imag.si,x.imag.bo,y.real.si,y.real.bo,y.imag.si,y.imag.bo,c.real.si,c.real.bo,c.imag.si,c.imag.bo);

    c = f_sub( &x,&y );
    printf( "(%d/%d+j%d/%d) - (%d/%d+j%d/%d) = %d/%d+j%d/%d\n",x.real.si,x.real.bo,x.imag.si,x.imag.bo,y.real.si,y.real.bo,y.imag.si,y.imag.bo,c.real.si,c.real.bo,c.imag.si,c.imag.bo);

    c = f_mul( &x,&y );
    printf( "(%d/%d+j%d/%d) * (%d/%d+j%d/%d) = %d/%d+j%d/%d\n",x.real.si,x.real.bo,x.imag.si,x.imag.bo,y.real.si,y.real.bo,y.imag.si,y.imag.bo,c.real.si,c.real.bo,c.imag.si,c.imag.bo);

    c = f_div( &x,&y );
    printf( "(%d/%d+j%d/%d) / (%d/%d+j%d/%d) = %d/%d+j%d/%d\n",x.real.si,x.real.bo,x.imag.si,x.imag.bo,y.real.si,y.real.bo,y.imag.si,y.imag.bo,c.real.si,c.real.bo,c.imag.si,c.imag.bo);
    puts("");

    FCOMP d = f_mul(&y, &z);
    FCOMP e = f_add(&x, &d);

    printf("(%d/%d+j(%d/%d))\n", x.real.si, x.real.bo, x.imag.si, x.imag.bo);
    printf("(%d/%d+j(%d/%d))\n", y.real.si, y.real.bo, y.imag.si, y.imag.bo);
    printf("(%d/%d+j(%d/%d))\n", z.real.si, z.real.bo, z.imag.si, z.imag.bo);
    printf("(x+y*z) = ");
    printf("(%d/%d+j(%d/%d))\n", e.real.si, e.real.bo, e.imag.si, e.imag.bo);

    return 0;
}