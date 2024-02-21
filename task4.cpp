#include <bits/stdc++.h>
#include <queue>
#include <unordered_set>
using namespace std;

long long prim(long long start,vector<bool>& visited,vector<vector<pair<long long,long long>>>& graph,unordered_set<long long>& mstNode,long long v){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push({0,start});
    visited[start]=true;
    vector<long long> dist(v,LLONG_MAX);
    dist[start]=0;
    long long res=0;
    while(!pq.empty()){
        auto currNode=pq.top().second;
      //  cout<<currNode<<" ";
        auto currDist=pq.top().first;
        pq.pop();
        if(mstNode.find(currNode)!=mstNode.end()){
            continue;
        }
        mstNode.insert(currNode);
        res+=currDist;
        for(auto edge:graph[currNode]){
            if(dist[edge.first]>edge.second){
                visited[edge.first]=true;
                dist[edge.first]=edge.second;
                pq.push({edge.second,edge.first});
            }
        }
    }
    return res;
}


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long v,e,k;
        cin>>v>>e>>k;
        vector<long long> parent(v);
        vector<vector<pair<long long,long long>>> graph(v);
        for(long long j=0;j<e;j++){
            long long x,y,w;
            cin>>x>>y>>w;
            graph[x].push_back({y,w});
            graph[y].push_back({x,w});
        }
        vector<long long> dist(v);
        vector<bool> visited(v);
        long long ans=0;
        for(int j=0;j<v;j++){
            if(!visited[j]){
                unordered_set<long long> mstNode;
                long long res=prim(j,visited,graph,mstNode,v);
                if(mstNode.size()%k==0){
                     ans+=res;   
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}