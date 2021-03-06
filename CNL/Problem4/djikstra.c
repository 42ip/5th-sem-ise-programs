// Given a graph find shortest paths from source to all nodes in the graph using Dijkstra’s shortest path algorithm.

#include <stdio.h>
#define inf 999

void dij(int n, int v, int cost[10][10],int dist[10]){
    int i, u, count, w, flag[10],min;
    for(i=1;i<=n;i++)
    {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }
    count = 2; 
    while(count<=n)
        {
            min=99;
            for(w=1;w<=n;w++)
                if(dist[w]<min && !flag[w])
                    min=dist[w],u=w;
                flag[u]=1;
                count++;
            for(w=1;w<=n;w++)
                if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
                    dist[w]=dist[u]+cost[u][w];
        }

}

int main()
{
    int n,v,i,j,cost[10][10],dist[10];
    printf("Enter n of nodes : "); scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       for (j=1;j<=n;j++)
       {
           scanf("%d",&cost[i][j]);
           if (cost[i][j] == 0)
                cost[i][j] = inf;
       } 
    }
    printf("Enter source node : ");
     scanf("%d",&v);
     dij(n,v,cost,dist);
    printf("Shortest path : ");
    for (i=1;i<=n;i++)
        if (i!=v)
            printf("%d -> %d, cost = %d \n",v,i,dist[i]);

}

