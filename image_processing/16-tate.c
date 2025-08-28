#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char str[1000];
    int img[320][240]; /*画像サイズにあわせて調節が必要*/
    int w, h;          /*画像の大きさ*/
    int d;             /*画像の階調*/
    int x, y;          /*画素を配列imgに読み込むためのループカウンタ*/
    FILE *fp1, *fp2, *fp3;

    // 入力用のファイルの準備
    if ((fp1 = fopen(argv[1], "r")) == NULL)
    {
        perror(argv[1]);
        exit(1);
    }

    // 出力用のファイルの準備
    if ((fp2 = fopen(argv[2], "w")) == NULL)
    {
        perror(argv[2]);
        exit(1);
    }

    /*ヘッダの読込み*/
    fscanf(fp1, "%s", str);       /*マジックナンバーの読込  */
    fscanf(fp1, "%d %d", &w, &h); /*画像の大きさの読込*/
    fscanf(fp1, "%d", &d);        /*画像の階調の読込*/

    /*画像部分を読み込む*/
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            fscanf(fp1, "%d", &img[x][y]);
        }
    }

    int img2[640][480]; // 出力用配列

    /*合成する画像の準備*/
    char str2[1000];
    int w2, h2; // 画像の大きさ
    int d2;     // 画像の階調

    // 入力用2のファイルの準備
    if ((fp3 = fopen(argv[3], "r")) == NULL)
    {
        perror(argv[3]);
        exit(1);
    }

    // ヘッダの読込み
    fscanf(fp3, "%s", str2);        // マジックナンバーの読込
    fscanf(fp3, "%d %d", &w2, &h2); // 画像の大きさの読込
    fscanf(fp3, "%d", &d2);         // 画像の階調の読込

    int img3[320][240];
    // 画像部分を読み込む
    for (y = 0; y < h2; y++)
    {
        for (x = 0; x < w2; x++)
        {
            fscanf(fp3, "%d", &img3[x][y]);
        }
    }

    // 幅比較
    int w3 = w;
    if (w < w2)
    {
        w3 = w2;
    }

    /*縦に合体*/
    for (y = 0; y < h + h2; y++)
    {
        for (x = 0; x < w3; x++)
        {
            if (y < h)
            {
                img2[x][y] = img[x][y]; // 上半分
                if (w <= x)
                {
                    img2[x][y] = 255;
                }
            }
            else
            {
                img2[x][y] = img3[x][y - h]; // 下半分
                if (w2 <= x)
                {
                    img2[x][y] = 255;
                }
            }
        }
    }

    /*出力*/
    fprintf(fp2, "%s\n%d %d\n%d\n", str, w3, h+h2, d); /*ヘッダ出力*/
    for (y = 0; y < h+h2; y++)
    {
        for (x = 0; x < w3; x++)
        {
            fprintf(fp2, "%d ", img2[x][y]); // 書き込まれているファイルが正しいかどうか注意
        }
        fprintf(fp2, "\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
