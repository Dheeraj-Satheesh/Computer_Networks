#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define max 11
int windowSize;
int array[max];
int sf = 0, sn = 0, rn = 0;
int frame = 0;
void sender(bool timer)
{
    if (timer)
    {
        printf("sent frame : %d\n", frame);
        sn = (sn + 1) % (windowSize + 1);
    }
    else
    {
        printf("sending frame : %d\n", frame);
        printf("Frame is lost or discarded\n");
        sn = (sn + 1) % (windowSize + 1);
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
        printf("Ack for frame lost: %d\n",frame+1);
    }
}
int main()
{
    int i = 0, j = 0;
    printf("Enter the window size: ");
    scanf("%d", &windowSize);
    for (; i < max; i++)
    {
        array[i] = (i % (windowSize + 1));
    }
    while (j < 11)
    {
        if (j == 0) // frame 0 sent successfully
        {
            frame = array[j];
            sender(true);
            receiver(true);
            printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, rn);
        }
        else if (j<4)
        {
            frame = array[j];
            sender(false);
            printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, rn);
            if(j==3)
            {
                j=1;
                sn=sf=1;
                while(j<4)
                {
                    printf("Resending frame : %d\n",array[j]);
                    frame = array[j];
                    sender(true);
                    printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, array[j+1]);
                    j++;
                }
                j=1;
                while(j<4)
                {
                    receiver(true);
                     printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, rn);
                     j++;
                }

            }

        }
        else
        {
            j--;
            // printf("%d\n",j);
            // printf("sf: %d\tsn: %d\trn: %d\tframe: %d\n", sf, sn, rn,frame);
            frame = array[j];
            sender(true);
            rn++;
            receiver(false);
            printf("sf: %d\tsn: %d\trn: %d\n", sf, sn, rn);
            for(int v=1;v<3;v++)
            {
                frame=array[j+v];
                sender(true);
                printf("sf: %d\tsn: %d\trn: %d\n", sf, sn,array[j+v+1]);
            }
            for(int v=1;v<3;v++)
            {
                receiver(true);
                printf("sf: %d\tsn: %d\trn: %d\n", sf+1, sn, sn);
            }
            break;
        }
        j++;
    }
    printf("\nName: Satheesh Dheeraj \nReg No: 21BCE2418");
    return 0;
}
