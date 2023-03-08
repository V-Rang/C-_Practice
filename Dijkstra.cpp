#include<iostream>

#define V 9

using namespace std;


int minDist(int dist[], bool seen[])
{
    int minindex = -1;
    int minval = INT_MAX;

    for(int i=0;i<V;i++)
    {
        if(seen[i] == false && dist[i]<minval)
        {
            minval = dist[i];
            minindex = i;
        }
    }
    return minindex;
}

void printdist(int dist[])
{
    cout <<"Shortest distance from source"<<endl;
    for(int i=0;i<V;i++)
    {
        cout << i << '\t'<<dist[i]<<endl;
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool seen[V];

    for(int i=0;i<V;i++)
    {
        dist[i] = INT_MAX;
        seen[i] = false;
    }


    dist[src] = 0;

    for(int i=0;i<V-1;i++)
    {
        int u = minDist(dist,seen);
        seen[u] = true;
        for(int j = 0; j<V;j++)
        {
            if(!seen[j] && graph[u][j] && dist[u] != INT_MAX && dist[j] > dist[u] + graph[u][j] ) dist[j] = dist[u] + graph[u][j];
        }
    }

    printdist(dist);
}

int main()
{

     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


    //why it fails for negative values A-5-B, A-2-C, B-(-10)-C
   // int graph[V][V] = { {0,5,2},{5,0,-10},{2,-10,0}};

    dijkstra(graph,0);


}
