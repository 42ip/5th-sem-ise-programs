#include <stdio.h>
#define inf 999
void dij(int n, int v, int mat[10][10], int node[10]){

    int min,u,w,count,flags[10];
    for(w = 1; w <= n;w++)
    {
        flags[w] = 0;
        node[w] = mat[v][w];
    }
    count = 2;
    while (count < n){
        min = inf;
        for(w = 1; w <= n; w++)
        {
            if (min > node[w] && !flags[w])
            {
                min = node[w];
                u = w;
            }
            
        }
        flags[u] = 1;
        for(w = 1; w <= n;w++){
            if ((node[w] > mat[u][w] + node[u]) && !flags[w]){
                node[w] = mat[u][w] + node[u];
            }
        }


        count++;
    }


}
void bmf(int costmat[10][10],int nodes){
    int count;
    do{
        count = 0;
        for(int i = 0; i < nodes; i++)
            for(int j = 0; j < nodes; j++)
                for(int k = 0; k < nodes;k++)
                    if (rt[i].dist[j] > costmat[i][j] + rt[k].dist[j])
                    {
                        rt[i].dist[j] > rt[i].dist[j] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }

    }while(count != 0)

}