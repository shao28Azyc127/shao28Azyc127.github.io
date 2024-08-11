#include<iostream>
#include<cmath>
using namespace std;
int ans=2147483647,d,n,r=0,t;
int rd[100000];
int pz[100000];
void dfs(int x,int y,int sum,int s2){
    int z=0;
    if(x==n){
        ans=min(ans,sum);
        return;
    }
    for(int i=x;i<x+y;i++)z+=rd[i];
    z=ceil((double)z/d)*pz[x];
    for(int i=1;i<=n-x-y+1;i++){
        dfs(x+y,i,sum+z,s2);
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>rd[i];
    for(int i=1;i<=n;i++)cin>>pz[i];
    for(int i=1;i<n;i++)dfs(1,i,0,0);
    cout<<ans;
    return 0;
}
