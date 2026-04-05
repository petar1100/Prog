#include <bits/stdc++.h>
using namespace std;

bool check(vector<pair<int,int>> prev,int x,int y){
    if(prev.empty()){
        return true;
    }
    for(int i=0;i<prev.size();i++){
        if(prev[i].first==x ||prev[i].second==y){
            return false;
        }
        if(abs(prev[i].first-x)==abs(prev[i].second-y)){
            return false;
        }
    }
    return true;
}

void all(int n,long long &c,vector<pair<int,int>> sol={},int x=0,int y=0){
    if(sol.size()==n){
        c++;
        return;
    }
    if(y>7){
        return;
    }
    if(check(sol,x,y)){
        if(x<7){
            all(n,c,sol,x+1,y);
            sol.push_back({x,y});
            all(n,c,sol,x+1,y);
            sol.pop_back();
        }
        else{
            all(n,c,sol,0,y+1);
            sol.push_back({x,y});
            all(n,c,sol,0,y+1);
            sol.pop_back();
        }
    }
    else{
        if(x<7){
            all(n,c,sol,x+1,y);
        }
        else{
            all(n,c,sol,0,y+1);
        }
    }
}

int main(){

    int n;
    long long sol=0;
    cin>>n;
    all(n,sol);
    cout<<sol;

    return 0;
}