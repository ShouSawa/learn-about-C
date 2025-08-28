#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define NUMBER 5
#define FAILED -1
int main(void)
{
}

//以下メソッドリスト

//---数値系-----------------------------------
//aとbの小さいほうを返す
int min2(int a,int b){
    return a<b ? a:b;
}

//3つの整数で小さいものを返す
int min3(int a,int b,int c){
    int tmp;
    //aとbの小さい方をtmp
    tmp = a<b ? a:b;
    //tmpとcの小さいほうをreturn
    return tmp < c ? tmp:c;
}

//xの3乗を返す
int cube(int x){
    return x*x*x;
}

//aとbの差を返す
int diff(int a, int b){
    return a > b ? a - b : b - a;
}

//1からnまでの総和を返す
int sumup(int n){
    int tmp = 0;
    for(int i = 1;i<n+1;i++){
        tmp += i;
    }
    return tmp;
}

//xのn乗を返す
double power(double x, int n){
    double tmp = 1.0;
    for(int i = 1; i <= n; i++){
        tmp *= x;
    }
    return tmp;
}

//警報をn回連続して発する関数
int alert(int n){
    for(int i = 0;i<n;i++){
        printf("alert\n");
    }
}

//正の整数を読み込んで返す
int scan_pint(void){
    int tmp;
    do {
        printf("正の整数を入力せよ：");
        scanf("%d", &tmp);
        if(tmp <= 0){
            puts("\a正でない数を入力しないでください．");
        }
    } while (tmp <= 0);
    return tmp;
}

//非負の整数を反転した値を返す
int rev_int(int num){
    int tmp = 0;
    if(num > 0) {
        do {
            tmp = tmp * 10 + num % 10;
            num /= 10;
        } while (num > 0);
    }
    return tmp;
}

//---配列-------------------------------------------------------------
//要素数nの配列vの最大値を返す
int max_of(int v[], int n){
    int max = v[0];
    for(int i = 1; i < n; i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

//配列の最小値を返す関数
int min_of(const int v[],int n){
    //要素数nの配列vの最小値を返す
    int tmp = 10e5;
    for(int i = 0;i<n;i++){
        if(v[i]<tmp){
            tmp = v[i];
        }
    }
    return tmp;
}

//要素数nの配列vの全要素を表示して改行
void print_array(const int v[], int n){
    printf("{ ");
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("}\n");
}

//要素数nの配列vの要素に0を代入
void set_zero(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = 0;
    }
}

//要素数nの配列vからkeyと一致する要素を探索
int search(const int v[], int key, int n){
    int i = 0;
    while (1){
        if(i == n){
            return FAILED;
        }
        if(v[i] == key){
            return i;
        }
        i++;
    }
}

//要素数nのint配列vの要素の並びを反転する
void rev_intary(int v[],int n){
    //反転用配列
    int tmp[5];
    for(int i = 0;i<n;i++){
        //配列を反転させてコピー
        tmp[i] = v[(n-1)-i];
    }
    for(int i = 0;i<n;i++){
        //元の配列を反転
        v[i] = tmp[i];
    }
}
//v1にv2を反転させてコピーする関数
void intary_rcpy(int v1[],const int v2[],int n){
    for(int i = 0;i<n;i++){
        v1[i] = v2[(n-1)-i];
    }
}

//{1,7,5,7,2,4,7}, key=7 -> {1,3,6}, 3を返却
//配列v内のkeyと等しい数字の数をcountに格納し，returnする．
//その時に配列idxにkeyと等しい要素のindexを格納していく．
int search_idx(const int v[],int idx[],int key,int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        if(v[i] == key){
            idx[count] = i;
            count++;
        }
    }
    return count;
}

//配列の各要素を2倍にする
void twice(int list[],int tmp){
    for (int i = 0; i < tmp; i++) {
        list[i] = list[i] * 2;
    }
}

//--行列----------------------------------------------------------
//同じサイズの行列の足し算を行う関数
// 行列のサイズ
#define ROWS 3
#define COLS 3
// 行列の足し算
void addMatrices(int A[ROWS][COLS], int B[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

//4行3列の行列mを表示
void mat_print(const int m[4][3]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            printf("%4d ",m[i][j]);
        }
	    printf("\n");
    }
}

//４行3列の行列aと3行4列の行列bの積を4行4列の行列cに格納する
void mat_mul(const int a[4][3], const int b[3][4], int c[4][4]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
	    c[i][j] = 0;
            for (int k = 0; k < 3; k++){
               c[i][j] += a[i][k] * b[k][j];
            }
        }
}

//2*3行列と3*2行列の掛け算を行う関数
// 行列のサイズ
#define ROWS_A 2
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 2
// 行列の掛け算
void multiplyMatrices(int A[ROWS_A][COLS_A], int B[ROWS_B][COLS_B], int result[ROWS_A][COLS_B]) {
    for (int i = 0; i < ROWS_A; ++i) {
        for (int j = 0; j < COLS_B; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < COLS_A; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

//４行3列の行列aとbの和を行列cに格納する
void mat_add(const int a[4][3], const int b[4][3], int c[4][3]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

//４行3列2の行列aとbの和を行列cに格納する
void mat_add(const int a[2][4][3], int c[4][3]){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = a[0][i][j] + a[1][i][j];
        }
    }
}

//---その他------------------------------------
//x段のピラミッドを表示する関数
void pyramid(int x){
    // ピラミッドを表示するループ
    for (int i = 1; i <= x; i++) {
        // 左側の空白を表示
        for (int j = 1; j <= x - i; j++) {
            printf(" ");
        }
        // "*"を表示
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        // 改行
        printf("\n");
    }
}

//九九表を配列に格納する関数
void kuku(int  list[10][10]){
    for(int i = 1;i<10;i++){
        for(int j = 1;j<10;j++){
            list[i][j] += i*j;
        }
    }
}

//うるう年の判定
int uruu(int y){
    if((y % 400 == 0) || (y % 4 == 0) && (y % 100 != 0)){ //うるう年の判定
	    return 1;
    }else{
	    return 0;
    }
}

//---文字列----------------------------------------------
//文字列の長さを返す
int str_length(const char s[]){
    int len = 0;
    while(s[len] != '\0'){
        len++;
    }
    return len;
}

//文字列を空文字列にする
void null_string(char s[]){
    int len = str_length(s);
    for(int i = 0;i<len;i++){
        s[i] = '\0';
    }
}

//cと一致する文字があればそのindexを返す，ないなら-1を返す．
int str_char(const char s[],int c){
    for(int i = 0;i<str_length(s);i++){
        if(s[i] == c){
            return i;
            }
    }
    return -1;
}

//引数cと同じ文字を文字列sから探し，個数を返す関数
int str_chunum(const char s[], int c){
    int len = 0;
    int count = 0;
    while(s[len] != '\0'){
        if(s[len] == c){
            count++;
        } 
        len++;
    }
    return count;
}//※int enter = getchar();をしないと，enterキーを数える文字としてしまう

//文字列sをn回表示する関数
void put_stringn(const char s[],int n){
    for(int i = 0;i < n;i++){
        printf("%s",s);
    }
    printf("\n");
}

//文字列sを反転して表示する関数
void put_stringr(const char s[]){
    for(int i = str_length(s);i>-1;i--){
        printf("%c",s[i]);
    }
    printf("\n");
}

//文字列の配列を反転する
void rev_string(char s[]){
    char tmp[100];
    for(int i = 0;i<str_length(s);i++){
        tmp[i] = s[str_length(s)-i-1];   
    }
    for (int i = 0; i< str_length(s); i++) {
        s[i] = tmp[i];
    }
}
//反転するやつ複数ver
void rev_strings(char s[][128],int n){
    char tmp[5][128];
    for(int i = 0;i<5;i++){
        for(int j = 0;j<str_length(s[i]);j++){
            tmp[i][j] = s[i][str_length(s[i])-j-1];
        }
    }
    for(int i = 0;i<5;i++){
        for(int j = 0;j<str_length(s[i]);j++){
            s[i][j] = tmp[i][j];
        }
    }
}

//文字列sに含まれる数字文字の出現回数を配列cntに格納
void str_dcount(const char s[], int cnt[]){
    int i = 0;
    while (s[i]){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt[s[i] - '0'];
        }
        i++;
    }
}

//文字列内の英字を大文字に変換
void str_toupper(char s[]){
    int i = 0;
    while (s[i]){
        s[i] = toupper(s[i]);
        i++;
    }
}

//文字列内の英字を小文字に変換
void str_toupper(char s[]){
    int i = 0;
    while (s[i]){
        s[i] = tolower(s[i]);
        i++;
    }
}

//文字列sの数字を除去する関数
void del_digit(char s[]){
    char tmp[100];
    int idx = 0;
    int count = 0;
    while(s[count]){
        if(s[count] < '0' || s[count] > '9'){
            tmp[idx] = s[count];
            idx++;
        }
        count++;
    }
    for (int i = 0; i< str_length(s); i++) {
        s[i] = tmp[i];
    }
}

//---ポインタ----------------------------------
//100より大きいなら100に，0より小さいなら0に
//adjust_point(&x);
void adjust_point(int *n){
    int tmp = *n < 0 ? 0 : *n;
    tmp = tmp > 100 ? 100 : tmp;
    *n = tmp;
}

//２値の交換
//swap(&a, &b);
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}