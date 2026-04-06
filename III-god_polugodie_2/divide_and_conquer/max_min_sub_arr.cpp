#include <bits/stdc++.h>
using namespace std;

int func(vector<int> v,int l,int mid,int r){
    int sum=0;
    int left=INT_MIN;
    for(int i=mid;i>=l;i--){
        sum+=v[i];
        left=max(left,sum);
    }
    sum=0;
    int right=INT_MIN;
    for(int i=mid+1;i<=r;i++){
        sum+=v[i];
        right=max(right,sum);
    }
    return left+right;
}

int maxSub(vector<int> v,int l,int r){
    if(l==r){
        return v[l];
    }
    int mid=(l+r)/2;
    return max({func(v,l,mid,r),maxSub(v,mid+1,r),maxSub(v,l,mid)});
}

int main() {

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxSub(a,0,n-1);


    return 0;
}