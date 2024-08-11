#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5 ;
LL vis[N],b[N];
LL n,ans;
LL Solve(LL t){
    vis[3]=3;
    vis[2]=2;
    vis[1]=1;
    b[3]=3;
    b[2]=2;
    b[1]=1;
    for(int i=4;i<=t;i++){
        int q=i%3,p=i/3;
        if((i-1)%3==0){
            vis[i]=vis[i-1];
        }
        else{
            if(q!=0)
            vis[i]=vis[i-p-1]+1;
            else
            vis[i]=vis[i-p]+1;
        }
    }
    for(int i=4;i<=t;i++){
        int q=i%3,p=i/3;
        if((i-1)%3==0){
            b[i]=1;
        }
        else{
            if(q!=0)
            b[i]=b[i-p-1]+1;
            else
            b[i]=b[i-p]+1;
        }
    }
}

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    Solve(n);
    cout<<vis[n]<<" "<<b[n];

    return 0;
}
