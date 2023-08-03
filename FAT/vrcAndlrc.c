#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char arr[20][10];
void display(int num, int len);
void vrc(int num, int len);
void lrc(int num, int len);
int main()
{
    int i;
    printf("Enter the length of words: ");
    int len;
    scanf("%d", &len);
    printf("Enter the number of words: ");
    int num;
    scanf("%d", &num);
    printf("Enter the data to be sent:");
    for (i = 0; i < num; i++)
    {
        scanf("%s", arr[i]);
    }
    vrc(num, len + 1);
    printf("\nvrc: \n");
    display(num, len + 1);
    lrc(num + 1, len);
    printf("lrc: \n");
    display(num + 1, len);
    return 0;
}
void display(int num, int len)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < len; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void vrc(int num, int len)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        int count = 0;
        for (j = 0; j < len - 1; j++)
        {
            if (arr[i][j] == '1')
                count++;
        }
        if (count % 2 == 0)
            arr[i][len - 1] = '0';
        else
            arr[i][len - 1] = '1';
    }
}
void lrc(int num, int len)
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        int count = 0;
        for (j = 0; j < num - 1; j++)
        {
            if (arr[j][i] == '1')
                count++;
        }
        if (count % 2 == 0)
            arr[num - 1][i] = '0';
        else
            arr[num - 1][i] = '1';
    }
}
