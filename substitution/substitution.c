#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>

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
//由於題目要求要26個character，若不是，則回報相應的提示，return 0。
        if (strlen(argv[1]) == 26)
        {
//先計算string length，但其實可以直接 == 26
            int strlength = strlen(argv[1]);
//iterated判斷是否符合要求
            for (int i = 0; i < strlength; i++)
            {
//若其中一個不是char，回報 "Key must only contain alphabetic characters.""，並return 1
                if (isalpha(argv[1][i]) == 0)
                {
                    printf("Key must only contain alphabetic characters.\n");
                    return 1;
                }
            }
//若其中一個char有跟前面char重複時，則回報"Key must not contain repeated characters."，並return 1
//nested for loop
//i先以第1個開始，j從第2個開始到第26個檢查，之後i =2檢查 j = 3 ~ j = 26，以此類推
//設定count = 1，若有檢查到重覆的，則count = count +1
//若最後count >= 2，則說明有重複的char, return 1
            for (int i = 0; i < strlength; i++)
            {   
                int count = 1;
                for (int j = i + 1; j < strlength; j++)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        count++ ;
                    }
                }
                if (count > 1)
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
//請求使用者輸入plaintext
//把argv[1]當作key (type = string)
//計算plaintext length
            string key = argv[1];
            string plaintext = get_string("plaintext: ");
            int ptlen = strlen(plaintext);
//print ciphertext
            printf("ciphertext: ");
//iteration判斷每一個char
//先判斷是否為alphabetic，若否則直接print out
//若是alphabetic時，則繼續下一步判斷大小寫
//把大寫-65 可以知道是plaintext的字母，然後再把剛剛得到的數字帶入key則可知道是key的第幾個相對應的位置(mapping)
//把小寫-97 可知道plaintext的字母，然後帶入key可知道相對應的位置
//由於不確定argv[1] = key 是輸入大寫還是小寫，因此在做轉換時，大寫時要轉成大寫(toupper)，小寫要轉小寫(tolower)
            for (int i = 0; i < ptlen; i++)
            {
                if (isalpha(plaintext[i]))
                {   
                    if (isupper(plaintext[i]))
                    {
                        printf("%c", toupper(key[plaintext[i] - 65]));
                    }
                    else if (islower(plaintext[i]))
                    {
                        printf("%c", tolower(key[plaintext[i] - 97]));
                    }
                }
                else
                {
                    printf("%c", (char) plaintext[i]);
                }
            }
            printf("\n");
            return 0;
        }
//若不滿26個character，則提示要補滿
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
//若argc != 2，則提示輸入規範
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}