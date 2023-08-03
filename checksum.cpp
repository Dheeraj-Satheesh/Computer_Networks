#include<bits/stdc++.h>
using namespace std;
string onesComplemen(string data)
{
    for(int i=0; i<data.length(); i++)
    {
        if(data[i]=='0')
            data[i]='1';
        else
            data[i]='0';
    }
    return data;
}
string checkSum(string data, int blockSize)
{
    int n=data.length();
    if(n%blockSize!=0)
    {
        int padding=blockSize-(n%blockSize);
        for(int i=0; i<padding; i++)
        {
            data='0'+data;
        }
    }
    string result="";
    for(int i=0; i<blockSize; i++)
    {
        result+=data[i];
    }
    for(int i=blockSize; i<n; i+=blockSize)
    {
        string nextBlock="";
        for(int j=i; j<i+blockSize; j++)
        {
            nextBlock+=data[j];
        }
        string addition="";
        int sum=0,carry=0;
        for(int k=blockSize-1; k>=0; k--)
        {
            sum+=(result[k]-'0')+(nextBlock[k]-'0');
            carry=sum/2;
            if(sum==0)
            {
                addition='0'+addition;
            }
            else if(sum==1)
            {
                addition='1'+addition;
            }
            else if(sum==2)
            {
                addition='0'+addition;
            }
            else
            {
                addition='1'+addition;
            }
            sum=carry;
        }
        string final="";
        if(carry==1)
        {
            for(int q=addition.length()-1; q>=0; q--)
            {
                if(carry==0)
                {
                    final=addition[q]+final;
                }
                else if(((addition[q]-'0')+carry)%2==0)
                {
                    final="0"+final;
                    carry=1;
                }
                else
                {
                    final="1"+final;
                    carry=0;
                }
            }
            result=final;
        }
        else
        {
            result=addition;
        }
    }
    return onesComplemen(result);
}
bool checker(string sentMessage, string receivedMessage, int blockSize)
{
    string senderChecksum=checkSum(sentMessage,blockSize);
    string receiverChecksum=checkSum(receivedMessage+senderChecksum,blockSize);
    if(count(receiverChecksum.begin(),receiverChecksum.end(),'0')==blockSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string sent_message= "10000101011000111001010011101101";
    int block_size=8;
    string recv_message= "10001101011000111001010011101101";
    cout<<"Check sum of the sent message is: ";
    cout<<checkSum(sent_message,block_size)<<endl;
    if(checker(sent_message,recv_message,block_size))
        cout<<"No Error found"<<endl;
    else
        cout<<"Error found"<<endl;
    return 0;
}
