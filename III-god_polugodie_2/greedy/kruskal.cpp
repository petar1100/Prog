#include <bits/stdc++.h>
using namespace std;

bool sporedi(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}
int kruskal(int n,vector<vector<int>> adj){
    sort(adj.begin(),adj.end(), sporedi);
    vector<unordered_set<int>> s(n);
    int count=0;
    for(auto i:adj){
        int temp=0;
        int u=i[0],temp1=-1;
        int v=i[1],temp2=-1;
        int d=i[2];
        for(auto a:s){
            if((temp1!=-1&&temp2!=-1)||a.empty()){
                break;
            }
            if(a.count(u)){
                temp1=temp;
            }
            if(a.count(v)){
                temp2=temp;
            }
            temp++;
        }
        if(temp1==-1||temp2==-1){
            for(auto a:s){
                if(a.empty()||a.count(temp1)||a.count(temp2)){
                    a.insert(u);
                    a.insert(v);
                    count+=d;
                    cout<<u<<" "<<v<<"a"<<endl;
                }
            }
        }
        else if(temp1!=temp2){
            int y=min(temp1,temp2),q=max(temp1,temp2);
            for(auto f:s[q]){
                s[y].insert(f);
            }
            cout<<u<<" "<<v<<"b"<<endl;
            count+=d;
        }
        if(s[0].size()==n-1){
            return count;
        }
    }
    return -1;
}

int main(){

    int n,k;
    cin>>n>>k;
    vector<vector<int>> adj(k);
    int a,b,c;
    for(int i=0;i<k;i++){
        cin>>a>>b>>c;
        adj[i].push_back(a);
        adj[i].push_back(b);
        adj[i].push_back(c);
    }
    cout<<kruskal(n,adj);

    return 0;
}
//9 14
//
//0 1 4
//
//0 7 8
//
//1 7 11
//
//1 2 8
//
//7 8 7
//
//7 6 1
//
//2 8 2
//
//6 8 6
//
//2 3 7
//
//2 5 4
//
//6 5 2
//
//3 5 14
//
//5 4 10
//
//3 4 9