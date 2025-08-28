//最初にコピー
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
//#define NUMBER 5

int main(int argc, char **argv)
{
    
    return 0;
}

/////////////////////////////////////////

/*constは受け取る配列の要素の値を変更しない
  ことを意味する．*/
void method(const int v[]){
}

int a(void)
{
    int name;

//ファイルから数値を1つ1つ読み取る
FILE *fp;
int n;
if (( fp = fopen( argv[1], "r" ) ) == NULL) { //ファイルを開く
    perror( argv[1] );
    exit( 1 );
}
while ( fscanf( fp, "%d", &n ) != EOF ) {
    printf("%d\n",n); //スペースごとに改行
}

//ファイルから読みよるver.2
int tmp = 0;
int arr[100];
char list[100];
FILE *f = fopen(argv[1],"r");
if( f == NULL ){
    printf("ファイルが開けません。");
} else {
    // ファイルの読み込み処理
    while( fgets(list,1000,f) != NULL){
        arr[tmp] = atoi(list);
        tmp++;
    }
}
fclose(f);


//mainでコマンドライン引数を取得する方法 argv[~]
int res = strcmp( argv[1], argv[2] ); //例


//--文字------------------------------------------------------
printf("%zu", sizeof("123")); // -> 4 文字の大きさ 123\0 
// \t : タブ文字
// \0 : ナル文字 これらは1文字扱い

char str[4] = {'A','B','C','\0'}; //文字配列の初期化
char str[4] = "ABC"; //上のやつと同じ

//文字列の途中で終端文字が含まれているのでそこで出力が終わる．
    char str[] = "ABC\0DEF";
    printf("文字列strは\"%s\"です．\n",str);

//文字の入力
scanf("%s", name); //&を置かない
scanf("%s", s[i]); //配列ver

//これでコマンドラインから1文字の入力ができる．
char c = getchar();

//文字列の配列
char s[][6] = {"Turbo", "NA", "DOHC"}; //最大6文字(\0入れて)

//文字全てにアクセス
while(s[len] != '\0'){

    len++;
}

strlen(str) //strの長さを返す

char s = toupper(s); //sを大文字に変換
char s = tolower(s); //sを小文字に変換

printf("s1 = \"%s\"\n", strcpy(s1, st)); //stをs1にコピーして表示
strncpy(s1, st, n) //stをs1にn文字までコピー

strcat(s1, "DEFG") //s1にDEFGを連結
strncat(s1, "DEFG", n) //s1にDEFGをn文字まで連結

strcmp(s1, s2) //s1とs2の大小関係を返す．
    //等しければ0,s1 > s2なら正，s1 < s2なら負の整数を返す
strcmp(s1, s2, n) //n文字目まで，大小関係を判定する

/* アルファベットの小文字か大文字かを判定 */
  if((moji>= 'a') && (moji<='z')){
    printf("アルファベットの小文字！\n");
  }
  else if((moji>= 'A') && (moji<='Z')){
    printf("アルファベットの大文字！\n");
  }
  else {
    printf("その他の文字！\n");
  }

//printfで"や%，\を表示する方法
printf("\"");
printf("%%");
printf("\\");

atoi(str) // strが指す文字列 -> int 
atol(str) // strが指す文字列 -> long
atoll(str) // strが指す文字列 -> long long
atof(str) // strが指す文字列 -> double

//ソート
// 3つの文字列を比較
    char str1[100];
    char str2[100];
    char str3[100];
    strcpy(str1,argv[1]);
    strcpy(str2,argv[2]);
    strcpy(str3,argv[3]);
// 文字列を大きい順にソート
    if (strcmp(str1, str2) < 0) {
        swap(str1, str2);
    }
    if (strcmp(str1, str3) < 0) {
        swap(str1, str3);
    }
    if (strcmp(str2, str3) < 0) {
        swap(str2, str3);
    }
//文字列を小さい順にソート
    /*if (strcmp(str1, str2) < 0) {
        swap(str1, str2);
    }
    if (strcmp(str1, str3) < 0) {
        swap(str1, str3);
    }
    if (strcmp(str2, str3) < 0) {
        swap(str2, str3);
    }*/

//最大の文字列を探す
if (argc < 2) {
    printf("文字列を入力してください。\n");
    return 1;
}
char *max_string = argv[1]; // 最初の文字列
printf("%d\n",atoi(argv[1]));
for (int i = 2; i < argc; i++) {
    printf("%d\n",atoi(argv[i]));
    if (strcmp(argv[i], max_string) > 0) {
        max_string = argv[i]; //max_stringを更新
    }
}


//---ポインタ-------------------------------------------------
printf("aのアドレス：%p",&a) //アドレスを表示




//----基礎---------------------------------------------------
//宣言
int n,n2;    
double d;


//出力
printf("%d\n",n);
puts("");
putchar('\n'); //改行


//intの入力
int n;  
printf("実数を入力せよ．:"); scanf("%d", &n);

int n,n2,n3;  
puts("二つ三つの実数を入力せよ．");
printf("整数a:"); scanf("%d", &n);
printf("整数b:"); scanf("%d", &n2);
printf("整数c:"); scanf("%d", &n3);

//doubleの入力
scanf("%lf", &d); 


//絶対値
abs(  )


//小数へキャスト
(double)(20 + 30)


//乱数
srandomdev();
int num = random()%6; //1~6の乱数

//乱数（上がうまく使えなかったとき用）
srand(time(NULL));
int num = rand()%6;//これが正しいかも


//if文
if(  ){
    
}else if(  ){

}else{

}


//2のべき乗のとき
(n & (n - 1)) == 0

//条件演算子 (aが1ならb, 0ならcを出力)
a ? b : c 


//switch文
switch (  ){
    case  : puts(""); break;
    case  : printf("%dは変数。\n",n); break;
    case  : 
}


//do文
int retry;
do{

    printf("もう一度するなら0を入力:"); 
    scanf("%d", &retry);
}while (retry == 0);


//while文
int count = 10;
while (count > 0){

    break;
    continue;
    count--;
}


//for文
for (int i = 0; i < n; i++){
    
}
for (int j = 0; j < n; j++){
    
}
for (int k = 0; k < n; k++){
    
}
for (int l = 0; l < n; l++){
    
}


//-----配列-----------------------------------------------
int array[5] = {, , , , };
int array[5] = {0}; //全要素を0で初期化
int array[5][5]; 
double[5];

//配列の要素数を求める．
int length = sizeof(array) / sizeof(array[0]);

//配列内の最大値，最小値を求める．
int max, min = tensu[0];
for (int m = 0; m < n; m++){
    if(tensu[m] > max){
        max = tensu[m];
    }
    if(tensu[m] < min){
        min = tensu[m];
    }
} 


//------行列の計算----------------------------------------------------
   //line1の読み込み
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){
            printf("line1, %d行%d列目:",i+1,j+1); scanf("%d", &line1[i][j]);
        }
    }

    //line2の読み込み
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            printf("line2, %d行%d列目:",i+1,j+1); scanf("%d", &line2[i][j]);
        }
    }

    //a*b行列　* c*d行列 = a*d行列
    //行列の計算
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 3; k++){
                sum[i][j] += line1[i][k] * line2[k][j];
            }       
        }
    }


//---ファイル-------------------------------------------------------
FILE *fp1;
if ( (fp1 = fopen("ファイル名", "r") ) == NULL ){
    perror("ファイル名");
    exit(1);
}

//ファイル内のデータを配列に書き込む
for (int i = 0; i < n; i++){
    fscanf(fp, "%d", &array[i]);
}

//ファイルのクローズ
fclose(fp1);


//画像処理に関しては，Mihon_photo_edit.cファイルを見ること

}