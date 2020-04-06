#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters = 0;
int words = 0;
int sentences = 0;

int main(void)
{
//詢問使用者的文字
    string text = get_string("Text: \n");

//開始計算小寫與大寫
//ASCII 大寫從65~90，小寫從97~122
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters += 1;
        }
    }
    
//開始計算words
//因為這裡是計算空格，因此計算words的時候要再加1
    for (int j = 0; j <= len; j++)
    {
        if ((text[j + 1] != ' ') && (text[j] == ' '))
        {
            words += 1;
        }
    }
    words += 1;
    
//開始計算sentences
//ASCII 33 for "!", 46 for ".", 63 for "?"
    for (int k = 0; k <= len; k++)
    {
        if ((text[k] == '.' || text[k] == '!' || text[k] == '?'))
        {
            sentences += 1;
        }
    }
    
//print letters, words, sentences.
    //printf("%i letter(s)\n", letters);
    //printf("%i word(s)\n", words);
    //printf("%i sentence(s)\n", sentences);
    
//計算index
//Formula: index = 0.0588 * L - 0.296 * S - 15.8
    float L = ((float)letters * 100 / words);
    //printf("L: %f\n", L);
    float S = ((float)sentences * 100 / words);
    //printf("S: %f\n", S);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("%f\n", index = 0.0588 * L - 0.296 * S - 15.8);
    int r_index = round(index);
//開始分級grades
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", r_index);
        return 0;
    }
    return 1;
}
