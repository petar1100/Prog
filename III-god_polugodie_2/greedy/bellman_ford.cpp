#include <bits/stdc++.h>
using namespace std;

vector<int> bellman(int n,vector<vector<int>> &adj,int start){
    vector<int> dist(n,INT_MAX);
    dist[start]=0;
    for(int i=0;i<n;i++){
        for(auto t:adj){
            int first=t[0];
            int second=t[1];
            int d=t[2];
            if(dist[first]!=INT_MAX && dist[second]>dist[first]+d){
                if(i==n-1){
                    return {-1};
                }
                dist[second]=dist[first]+d;
            }
        }
    }
    return dist;
}

int main() {

    int n,k,start;
    cin>>n>>k>>start;
    vector<vector<int>> adj(k);
    int a,b,c;
    for(int i=0;i<k;i++){
        cin>>a>>b>>c;
        adj[i].push_back(a);
        adj[i].push_back(b);
        adj[i].push_back(c);
    }
    vector<int> dist= bellman(n,adj,start);
    for(int i=0;i<dist.size();i++){
        cout<<i<<":"<<dist[i]<<endl;
    }

    return 0;
}