#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//#define NUMBER 5

typedef struct{
    int si; //分子
    int bo; //分母
}BUNSU;

#define abs(x) x < 0 ? -x : x

//最大公約数
int gcd( int a, int b ){
    if( b == 0 ){
	return a;
    }else{
	return gcd( b, a%b );
    }	
}

//約分
BUNSU approx( BUNSU a ){
    BUNSU approx;
    int g = gcd( a.si, a.bo );
    approx.si = a.si / g;
    approx.bo = a.bo / g;
    return approx;
}

//分数の足し算
BUNSU b_add(BUNSU x, BUNSU y){
    BUNSU res;
    res.si = x.si * y.bo + y.si * x.bo;
    res.bo = x.bo * y.bo;
    return approx( res );
}

//分数の引き算
BUNSU b_sub(BUNSU x, BUNSU y){
    BUNSU res;
    res.si = x.si * y.bo - y.si * x.bo;
    res.bo = x.bo * y.bo;
    return approx( res );
}

/*
BUNSU b_mul(BUNSU x, BUNSU y){

}

BUNSU b_div(BUNSU x, BUNSU y){

}

*/

int main(int argc, char **argv)
{
    BUNSU a,b,c;

    a.si = atoi( argv[1] );
    a.bo = atoi( argv[2] );

    b.si = atoi( argv[3] );
    b.bo = atoi( argv[4] );

    c = b_add( a,b );
    printf( "%d/%d + %d/%d = %d/%d\n",a.si,a.bo,b.si,b.bo,c.si,c.bo );

    c = b_sub( a,b );
    printf( "%d/%d - %d/%d = %d/%d\n",a.si,a.bo,b.si,b.bo,c.si,c.bo );
    
    /*
    c = b_mul( a,b );
    printf( "%d/%d * %d/%d = %d/%d\n",a.si,a.bo,b.si,b.bo,c.si,c.bo );

    c = b_div( a,b );
    printf( "%d/%d / %d/%d = %d/%d\n",a.si,a.bo,b.si,b.bo,c.si,c.bo );
    */
    
    return 0;
}
