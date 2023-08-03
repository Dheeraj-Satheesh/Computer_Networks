#include<stdio.h>
#include<string.h>
void lrccheck(char data[5][9])
{
    for(int i=0;i<8;i++)
    {
        int count=0;
        for(int j=0;j<4;j++)
        {
            if(data[j][i]=='1')
                count++;
        }
        //even parity check
        if(count%2==0)
            data[4][i]='0';
        else
            data[4][i]='1';
    }
}
int main()
{
    char arr[5][9];
    printf("Enter the data which has to be sent:");
    for(int i=0;i<4;i++)
    {
        scanf("%8s",arr[i]);
    }
    lrccheck(arr);
    printf("Data to be sent is : \n");
    for(int i=0;i<5;i++)
    {
        printf("%s\n",arr[i]);
    }
    printf("Parity bit is %s\n",arr[4]);
    return 0;
}