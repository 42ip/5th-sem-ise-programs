#include <stdio.h>
#include <stdlib.h>
struct node{
    int dist[10];
    int from[10];
}rt[10];

int main(){
    int nodes,i,j,cost,count;
    int costmat[10][10];
    printf("Enter the number of nodes:");
    scanf("%d",&nodes);
    printf("Enter the cost matrix\n");
    for(i = 0; i < nodes; i++)
        for(j = 0 ; j < nodes; j++)
        {
            scanf("%d",&cost);
            costmat[i][j] = (i == j) ? 0 : cost;
            rt[i].dist[j] = cost;
            rt[i].from[j] = j;
            
        }
    do
    {
    count = 0;
    for( i = 0; i < nodes;i++)
        for (j = 0; j < nodes;j++)
            for (int k = 0; k < nodes;k++)
            {
                if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]){
                    rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[i];
                    rt[i].from[j] = k;
                    count++;
                }
            }
    }while(count != 0);
    i = 0;
    printf("For node %d,costs are\n",i + 1);
    for(j = 0; j < nodes; j++)
        printf("Node %d via %d with cost %d\n",j+1,rt[i].from[j],rt[i].dist[j]);
    

}