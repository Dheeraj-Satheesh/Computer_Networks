#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
//length of generator polynomial
#define N strlen(genPoly)
//declaring global variables
char data[30];//data to be transmitted
char received[30];//data which is received
char checkValue[30];//crc value
char genPoly[10];//generator polynomial
int dataLength,i,j;//some useful variables
//fucntion that performs xor operations
void xor()
{
    // here we are checking from '1' index because, at '0' index we are already know 1 is there
    // as '1' is there at '0' index of checkValue we are calling this xor() function
    for(j=1; j<N; j++)
    {
        checkValue[j]=((checkValue[j]==genPoly[j])?'0':'1');
    }
}
void crc(char data[]);
//function to check for errors on the receiver side
void receiver()
{
    printf("Enter the received data: ");
    scanf("%s",received);
    //now call crc function to find the syndrome or the remainder
    crc(received);
    //to check if the remainder is zero to find the error
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
//function to generate the reduntant bits
void crc(char data[])
{
    //initializing the checkValue, first we will add first N digits of data into checkValue
    for(i=0; i<N; i++)
        checkValue[i]=data[i];
    do
    {
        //check if first bit is '1' and call xor function or else continue moving the bits by 1 position
        if(checkValue[0]=='1')
            xor();// we are actually doing the division part
        //if above condition fails then we can directly shift the bits of checkValue by 1
        for(j=0; j<N-1; j++)
            checkValue[j]=checkValue[j+1];
        //appending the next data bit from data array
        checkValue[j]=data[i++];// here we can observe that i value will be N once it comes here because of the above for loop which is outside
        //do-while loop
    }
    while(i<=dataLength+N-1);
    //run the loop until the data ends
}
int main()
{
    printf("Enter the data to be transmitted: ");
    scanf("%s",data);
    printf("Enter the generator polynomial: ");
    scanf("%s",genPoly);
    dataLength=strlen(data);
    // now to append N-1 zeroes to the data, here N refers to strlen of genPoly
    for(i=dataLength; i<dataLength+N-1; i++)
        data[i]='0';
    // now to call the cyclic redundancy check function
    crc(data);
    printf("The CRC or check value is : %s\n",checkValue);
    // now to append the data with checkValue(crc)
    for(i=dataLength; i<dataLength+N-1; i++)
        data[i]=checkValue[i-dataLength];
    printf("The codeword transmitted is : %s\n",data);
    //now call the receiver function
    receiver();
    return 0;
}
