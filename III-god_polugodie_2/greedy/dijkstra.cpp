#include <bits/stdc++.h>
using namespace std;


int main() {

    int n,k,start,end;
    cin>>n>>k>>start;
    int a,b,c;
    vector<vector<pair<int,int>>> adj(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<k;i++){
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    vector<int> dist(n,INT_MAX);
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        auto t=pq.top();
        pq.pop();
        int place=t.second;
        int d=t.first;
        for(auto i:adj[place]){
            if(d+i.first<dist[i.second]){
                dist[i.second]=d+i.first;
                pq.push({dist[i.second],i.second});
            }
        }
    }
    for(auto i=0;i<n;i++){
        cout<<i<<":"<<dist[i]<<endl;
    }


    return 0;
}