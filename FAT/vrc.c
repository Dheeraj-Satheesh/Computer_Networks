#include <stdio.h>
#include <string.h>
// Function to perform VRc (Vertical Redundancy Check) and calculate the parity bit
void vcr(char data[])
{
    int i, count = 0;
    for (i = 0; data[i] != '\0'; i++)
    {
        if (data[i] == '1')
            count++;
        else
            continue;
    }
    // Implementing even parity
    if (count % 2 == 0)
        data[i] = '0';
    else
        data[i] = '1';
    // Adding a null character at the end of the string
    data[i + 1] = '\0';
}
int main()
{
    char input[100];
    printf("Enter the data to be sent: ");
    scanf("%s", input);
    vcr(input);
    // Printing the data with the parity bit
    printf("The data sent with parity bit: %s\n", input);
    printf("The parity bit is: %c\n", input[strlen(input) - 1]);
    return 0;
}
