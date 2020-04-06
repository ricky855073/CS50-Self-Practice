#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


//因為要有command-line argument，因此main裡面要有 (int argc, string array[])
//int argc是指 當command-line argument有兩項
//string argv[] 是只 指令的第?項
//example: ./caesar 12345
//argv[0] == ./caesar
//argv[1] == 12345
//int argc == 2 by argv[0] & argv[1]
int main(int argc, string argv[])
{
//依據題目要求 只能在command後面接一項，因此全部的argc == 2
    if (argc == 2)
    {
        int len = strlen(argv[1]);
//要先計算strlen of argv，之後iterate判斷每個character是否為digits
        //printf("strlen: %i\n", len);
        for (int i = 0; i < len; i++)
        {
//以isdigit()判斷是否每一個位置都是digit
//若不是digit，則isdigit() == 0
//提示應該要用 ./caesar key做輸入
//不要隨便亂用break，會出事!!!
            if (isdigit(argv[1][i]) == 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
                break;
            }
        }
        printf("Success\n");
    }
//若argc不是2，提示應該要用 ./caesar key做輸入，以argc = 2為command
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
//現在開始把string轉成integer
    int int_argv = atoi(argv[1]);
    //printf("%d\n", int_argv);
    string ptext = get_string("plaintext: ");
//現在開始加
//先計算plaintext的長度 strlen(ptext)
    int ptlen = strlen(ptext);
//算module 26，存入argvmod
    int argvmod = int_argv % 26;
    //printf("%i\n", argvmod);
//由於題目要求print ciphertext，之後才print各個character
    printf("ciphertext: ");
//下面開始逐字判斷
    for (int i = 0; i < ptlen; i++)
    {
//以isalpha()判斷是否為alphabetic
        if (isalpha(ptext[i]))
        {
//以isupper()判斷是否為uppercase
            if (isupper(ptext[i]))
            {
//以ASCII系統做判斷，A = 65 ~ Z = 97
//若原本的character以十進制計算後超過97，則扣掉26回到65開始的判斷式
//若原本的character以十進制計算後沒有超過97，則正常計算不做更動
                if (((int) ptext[i] + argvmod) <= 90)
                {
                    printf("%c", (char)((int) ptext[i] + argvmod));
                }
                else
                {
                    printf("%c", (char)((int) ptext[i] + argvmod - 26));
                }
            }
//以islower()判斷是否為lowercase
            else if (islower(ptext[i]))
            {
//以ASCII系統做判斷，a = 97 ~ z = 122
//若原本的character以十進制計算後超過122，則扣掉26回到97開始的判斷式
//若原本的character以十進制計算後沒有超過122，則正常計算不做更動
                if (((int) ptext[i] + argvmod) <= 122)
                {
                    printf("%c", (char)((int) ptext[i] + argvmod));
                }
                else
                {
                    printf("%c", (char)((int) ptext[i] + argvmod - 26));
                }
            }
        }
//若不是alphabetic，則print出原本的character
        else
        {
            printf("%c", ptext[i]);
        }
    }
//最後print newline換行
    printf("\n");
//運行順利，return 0結束
    return 0;
}