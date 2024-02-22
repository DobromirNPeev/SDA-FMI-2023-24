#include <bits/stdc++.h>
using namespace std;

bool dfs(int v,int parent,vector<bool>& visited,vector<int> graph[]){
    visited[v]=true;
    for(auto w:graph[v]){
        if(visited[w] && parent!=w){
            return true;
        }
        if(!visited[w]){
            if(dfs(w,v,visited,graph))
                return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<int> graph[1000000];
        int v,e;
        cin>>v>>e;
        for(int j=0;j<e;j++){
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<bool> visited(v+1,false);
        int count=0;
        for(int j=0;j<v;j++){
            if(!visited[j]){
                count+=dfs(j,-1,visited,graph);
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}