#include <bits/stdc++.h>

using namespace std;

int n;

bool visited[1000001];

vector<int> adj[1000001];

stack<int> stk;

stack<int> sorted;

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

void dfs(int source)
{
    cout<<"Source:"<<source<<endl;

    visited[source]=true;

    for(int i=0;i<adj[source].size();i++)
    {
        if(! visited[adj[source][i]] )
            dfs(adj[source][i]);
    }

    //cout<<"push::"<<source<<endl;
    sorted.push(source);

    return ;
}

int main()
{
    int n,m;

    scanf("%d %d",&n,&m);

    while(m--){

        int u, v;

        scanf("%d %d",&u,&v);

        addEdge(u,v);
    }

    for(int i=1;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }

        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
                 dfs(i);

        }


        while(!sorted.empty())
        {
            printf("%d ",sorted.top());
            sorted.pop();
        }


    return 0;
}
