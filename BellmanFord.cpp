#include<bits/stdc++.h>
using namespace std;

void bellmanFord()
{
    int v,n_edge;
    cout<<"enter number of vertices and number of edges "<<endl;
    cin>>v>>n_edge;
    vector<vector<int>>edges;
    for(int i=0;i<n_edge;i++)
    {
        int u,v,wt;
        cout<<"enter start  end  weight "<<endl;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});        
    }
    vector<int> distance(v,1e7);
    vector<int>parent(v,-1);
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }
    int S;
    cout<<"enter starting node"<<endl;
    cin>>S;
    parent[S]=-1;
    distance[S]=0;
    for(int i=1;i<v;i++)
    {
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            if(distance[u]+wt<distance[v])
            {
                parent[v]=u;
                distance[v]=distance[u]+wt;                
            }
        }
    }
    for(auto x:edges)
    {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            if(distance[u]+wt<distance[v])
            {
                cout<<"negative cycle exist !"<<endl;                
                return ;
            }
    }

    for(int i=0;i<v;i++)
    {
        if(i!=S)
        {
            cout<<"distance of "<<i<<"th node from start is :"<<distance[i]<<endl;
            cout<<"path follows "<<i;
            int j=parent[i];
            do
            {
                cout<<"<-"<<j;
                j=parent[j];                
            }while(j!=-1);
            cout<<endl;
        }
    }

}
int main()
{
    bellmanFord();
    return 0;
}