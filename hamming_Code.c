// c program to encodes 4-bit data word using (7,4) hamming code
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//declaring the global variables
int codeword[7];
int data[4];
int syn[3];
//function to display the arrray
void display(int num[],int n)
{
    int i=0;
    for (; i<n; i++)
    {
        /* code */
        printf("%d",num[i]);
    }
    printf("\n");
}
//function to encode the data word
void encodeHamming(int arr[])
{
    int i,n=7,d=4;
    //int codeword[7];

    // the parity bits are added at 0,1,2,3 position of codeword and remaining will be added with dataword
    // now we will add the data words first to codeword
    codeword[0]=arr[0];
    codeword[1]=arr[1];
    codeword[2]=arr[2];
    codeword[3]=arr[3];

    // now we will calculate the redundant bits
    codeword[4]=arr[0]^arr[2]^arr[3];
    codeword[5]=arr[0]^arr[1]^arr[2];
    codeword[6]=arr[1]^arr[2]^arr[3];

    printf("The code word to be sent is: \n");
    display(codeword,7);
}

// the decoding function of the same
void decode()
{
    syn[2]=codeword[4]^codeword[0]^codeword[2]^codeword[3];
    syn[1]=codeword[5]^codeword[0]^codeword[1]^codeword[2];
    syn[0]=codeword[6]^codeword[1]^codeword[2]^codeword[3];
    printf("The syndrome calculated is : \n");
    display(syn,3);
    if(syn[0]==0)
    {
        if(syn[1]==0)
        {
            if(syn[2]==0)
            printf("No error\n");
            else
            printf("Error at q0\n");
        }
        else{
            if(syn[2]==0)
            printf("error at q1\n");
            else
            printf("error at b2\n");
        }
    }
    else{
         if(syn[1]==0)
        {
            if(syn[2]==0)
            printf("error at q2\n");
            else
            printf("error at b0\n");
        }
        else{
            if(syn[2]==0)
            printf("error at b3\n");
            else
            printf("error at b1\n");
        }
    }
}
int main()
{
    //int data[4];
    printf("Enter the 4-bit data word: \n");
    scanf("%1d%1d%1d%1d",&data[0],&data[1],&data[2],&data[3]);//taking input of 4-bits individually
    //call the hamming function to encode the following data;
    encodeHamming(data);
    // now we will change one bit in codeword to check whether it will be identified at the receiver side or not
    if(codeword[2]==0)
    codeword[2] =1;
    else
    codeword[2]=0;
    printf("Codeword after some errors: \n");
    display(codeword,7);
    //now calling receiver function
    decode();
    return 0;
}
