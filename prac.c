#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define N strlen(genPoly)
char data[30];
char received[30];
char checkValue[30];
char genPoly[10];
int dataLength,i,j;
void xor()
{
    for(j=1; j<N; j++)
    {
        checkValue[j]=((checkValue[j]==genPoly[j])?'0':'1');
    }
}
void crc(char data[]);
void receiver()
{
    printf("Enter the received data: ");
    scanf("%s",received);
    crc(received);
    for(i=0; i<N-1; i++)
    {
        if(checkValue[i]!='0')
            break;
    }
    if(i==N-1)
        printf("No error detected\n");

    else
        printf("Error detected\n");
}
void crc(char data[])
{
    for(i=0; i<N; i++)
        checkValue[i]=data[i];
    do
    {
        if(checkValue[0]=='1')
            xor();
        for(j=0; j<N-1; j++)
            checkValue[j]=checkValue[j+1];
        checkValue[j]=data[i++];
    }
    while(i<=dataLength+N-1);
}
int main()
{
    printf("Enter the data to be transmitted: ");
    scanf("%s",data);
    printf("Enter the generator polynomial: ");
    scanf("%s",genPoly);
    dataLength=strlen(data);
    for(i=dataLength; i<dataLength+N-1; i++)
        data[i]='0';
    crc(data);
    printf("The CRC or check value is : %s\n",checkValue);
    for(i=dataLength; i<dataLength+N-1; i++)
        data[i]=checkValue[i-dataLength];
    printf("The codeword transmitted is : %s\n",data);
    receiver();
    return 0;
}

