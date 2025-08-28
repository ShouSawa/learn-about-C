#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    int img2[320][240]; // 出力用配列

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

    bool firstIsBig = true; // 1枚目の画像は大きいか

    // 幅比較
    int wBig = w;
    int wSmall = w2;
    if (w < w2)
    {
        wBig = w2;
        wSmall = w;
        firstIsBig = false;
    }
    // 高さ比較
    int hBig = h;
    int hSmall = h2;
    if (h < h2)
    {
        hBig = h2;
        hSmall = h;
        firstIsBig = false;
    }

    // 小さい画像を貼る範囲決め
    int UD = (hBig - hSmall) / 2;
    int LR = (wBig - wSmall) / 2;

    /*合体*/
    for (y = 0; y < hBig; y++)
    {
        if (y < UD || y >= UD + hSmall)
        {
            for (x = 0; x < wBig; x++)
            {
                if (firstIsBig)
                {
                    img2[x][y] = img[x][y];
                }
                else
                {
                    img2[x][y] = img3[x][y];
                }
            }
        }
        else
        {
            for (x = 0; x < wBig; x++)
            {
                if (x < LR || x >= LR + wSmall)
                {
                    if (firstIsBig)
                    {
                        img2[x][y] = img[x][y];
                    }
                    else
                    {
                        img2[x][y] = img3[x][y];
                    }
                }
                else
                {
                    if (firstIsBig)
                    {
                        img2[x][y] = img3[x - LR][y - UD];
                    }
                    else
                    {
                        img2[x][y] = img[x - LR][y - UD];
                    }
                }
            }
        }
    }

    /*出力*/
    fprintf(fp2, "%s\n%d %d\n%d\n", str, wBig, hBig, d); /*ヘッダ出力*/
    for (y = 0; y < hBig; y++)
    {
        for (x = 0; x < wBig; x++)
        {
            fprintf(fp2, "%d ", img2[x][y]); // 書き込まれているファイルが正しいかどうか注意
        }
        fprintf(fp2, "\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
