#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
int frame=0,i=0;
int sn,rn;
int totalFrames=5;
void sender(int frame,bool timer)
{
    if(timer)
    {
        printf("sent frame : %d\n",frame);

    }
    else
    {
        printf("sending frame : %d\n",frame);
        printf("Frame is lost\nTimeOut\n");
    }
}
void receiver(int frame,bool timer)
{
    if (timer)
    {
        printf("Ack for frame sent: %d\n",frame);
    }
    else
    {
        printf("Ack for frame lost: %d\nTimeOut\n",(frame==0)?1:0);
    }
}
void success()
{
    sender(frame,true);
    sn=rn=frame;
    printf("sn: %d\n",sn);
    frame=(frame==0)?1:0;
    receiver(frame,true);
    sn=rn=frame;
    printf("rn: %d\n",rn);
}
int main()
{

    while(i<totalFrames)
    {
        if(i<2) //2 frames are sent successfully
        {
            success();
        }
        else if(i==2)
        {
            //here the frame is lost
            sender(frame,false);
            printf("sn: %d\n",sn);
            printf("\nresending the frame: %d\n",frame);
            success();
        }
        else if(i==3)// here the ack is lost
        {
            sender(frame,true);
            printf("sn: %d\n",sn);
            receiver(frame,false);
            printf("\nresending the frame: %d\n",frame);
            success();
        }
        i++;
    }
    printf("\nName: Satheesh Dheeraj \nReg No: 21BCE2418");
    return 0;
}
