#include <iostream>
#include <climits>
using namespace std;

//Minimum time
int minTime(int distance[], bool visitedStatus[])
{
    int minimum=INT_MAX,index;

    for(int k=0;k<6;k++)
    {
        if(visitedStatus[k]==false && distance[k]<=minimum)
        {
            minimum=distance[k];
            index=k;
        }
    }
    return index;
}

// Dijkstra Algorithm
void Dijkstra(int graph[6][6],int startNode)
{
    //create a distance array and visited boolean array
    int distance[6];
    bool visitedStatus[6];

    //initialize all values to infinity in distance array
    //initialize all values to false in visited array
    for (int i=0; i<6; i++){
        distance[i]= INT_MAX;
        visitedStatus[i]= false;
    }
    
    // Start node distance is 0
    distance[startNode] = 0;   

    for(int k = 0; k<6; k++)
    {
        int m=minTime
    (distance,visitedStatus);
        visitedStatus[m]=true;
        for(int k = 0; k<6; k++)
        {
            if(!visitedStatus[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from start node 6"<<endl;
    double sum=0;
    for(int k = 0; k<6; k++)
    {
        cout<<k<<"         |         "<<distance[k]<<endl;
        sum = sum + distance[k];

    }

        cout<<"Average is "<< (sum/5)<< endl;
}

int main()
{
    int graph[6][6]={
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}};
    Dijkstra(graph,6);
    return 0;
}
