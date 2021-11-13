#include <stdio.h>
#include <stdlib.h>

#define min(x,y) x > y ? x : y
int main()
{
    int inflow[10];
    int bucketsize,outflow,input,i,recievedtill=0,remaining=0,sent=0,dropped=0;
    printf("Enter the size of the bucket : ");
    scanf("%d",&bucketsize);
    printf("Enter the amount the bucket allows out at a time : ");
    scanf("%d",&outflow);
    i = 0;
    do{
        printf("Enter the size of the packet at second %d : ",i + 1);
        scanf("%d",&inflow[i]);
        i += 1;
        printf("Do you have more inputs ? (0/1)"); scanf("%d",&input);
    }while(input && i < 10);
    recievedtill = i;
    printf("Now showing the status of the bucket as it flows\n");
    printf("Time\tRecieved\tSent\tDropped\tRemaining\n");
    for(i = 0 ;  remaining || i < recievedtill; i++)
    {
        printf("%d\t%d\t\t",i+1,inflow[i]);
        if (i < recievedtill)
            remaining += inflow[i];
        if (remaining > bucketsize)
        {
            dropped = remaining - bucketsize;
            remaining = bucketsize;
        }
        sent = remaining < outflow ? remaining : outflow;
        remaining = remaining < outflow ? 0 : remaining - outflow;
        printf("%d\t%d\t%d\n",sent,dropped,remaining);
        dropped = 0;
    }

}