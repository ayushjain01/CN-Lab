#include<bits/stdc++.h>
using namespace std;

void dijkstras()
{
    int v,n_edges;
    cout<<"enter number of vertices and number of edges : "<<endl;    
    cin>>v>>n_edges;
    vector<pair<int,int>>adj[v];
    for(int i=0;i<n_edges;i++)
    {
        int u,v,wt;
        cout<<"enter start end weight :"<<endl;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    vector<int> distance(v,1e9);
    vector<int> parent(v,-1);
    for(int i=0;i<v;i++)parent[i]=i;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int S;    
    cout<<"enter starting node :"<<endl;
    cin>>S;
    parent[S]=-1;
    distance[S]=0;
    pq.push({0,S});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int dist=pq.top().first;
        pq.pop();
        for(auto x:adj[node])
        {
            int next_node=x.first;
            int wt=x.second;
            if(dist+wt<distance[next_node])
            {
                distance[next_node]=dist+wt;
                pq.push({dist+wt,next_node});
                parent[next_node]=node;
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        if(i!=S)
        {
            cout<<"distance of "<<i<<"th node is : "<<distance[i]<<endl;
            cout<<"path follows : "<<i;
            int j=parent[i];
            do
            {
                cout<<" <- "<<j;
                j=parent[j];
            }while(j!=-1);
            cout<<endl;
        }
    }


    
}
int main()
{
    dijkstras();
    return 0;
}