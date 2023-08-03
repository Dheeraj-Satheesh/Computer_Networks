#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// to perform vcr and calculate the parity bit
int vcr(char data[])
{
    int i, count = 0;
    for (i = 0; data[i] != '\0'; i++)
    {
        if (data[i] == '1')
            count++;
        else
            continue;
    }
    // we are implementing the even parity
    if (count % 2 == 0)
        data[i] = '0';
    else
        data[i] = '1';
    // putting the null character in the string to show the end of the string
    data[i + 1] = '\0';
}
int main()
{
    char input[100];
    printf("Enter the data to be sent: ");
    scanf("%s", input);
    vcr(input);
    printf("Parity bit is to be added is: %d\n",input[9]);
    printf("The data sent is: %s\n", input);
    return 0;
}
