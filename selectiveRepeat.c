#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define max 9
int windowSize;
int array[max];
int sf = 0, sn = 0, rn = 0;
double m;
int frame = 0;
int temp;
void sender(bool timer)
{
    if (timer)
    {
        printf("sent frame : %d\n", frame);
        sn = (sn + 1) % (temp);
    }
    else
    {
        printf("sending frame : %d\n", frame);
        printf("Frame is lost \n");
        sn = (sn + 1) % (temp);
    }
}
void receiver(bool timer)
{
    if (timer)
    {
        sf = (sf + 1) % (windowSize + 1);
        frame = sf;
        rn = (rn + 1) % (windowSize + 1);
        printf("Ack for frame sent: %d\n", frame);
    }
    else
    {
        printf("Negative Ack for frame : %d\n",rn);
    }
}
void cummalitiveAck()
{
    printf("Ack for frame sent: %d\n",frame);
    sf=sn=frame;
    rn=frame;
}
int main(){
    int i = 0, j = 0;
    printf("Enter the value of m: ");
    scanf("%lf",&m);
    printf("Enter the window size: ");
    scanf("%d", &windowSize);
    temp=(int)(pow(2,(double)m));
    for (; i < max; i++)
    {
        array[i] = (i % temp);
    }
    while(j<max)
    {
        if(j==0)
        {
            frame = array[j];
            sender(true);
            receiver(true);
            printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, rn);

        }
        else if(j==1)
        {
            frame = array[j];
            sender(false);
            printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, rn);
        }
        else if(j<4)
        {
            frame = array[j];
            sender(true);
            printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, rn);
        }
        else if(j==4){
        receiver(false);
        frame=rn;
        printf("Resending the frame: %d\n",frame);
        sender(true);
        frame=array[4];
        cummalitiveAck();
        printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, rn);
        }
        j++;
    }
 printf("\nName: Satheesh Dheeraj \nReg No: 21BCE2418");
return 0;
}
