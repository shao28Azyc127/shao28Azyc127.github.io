#include <bits/stdc++.h>
using namespace std;
int n,t;
int w[100005],v[100005],arr[100005],dp[100005],minn=1e9;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>t;
    for(int i=2;i<=n;i++){
        cin>>w[i];
        dp[i]=1e9;
        arr[i]=arr[i-1]+w[i];
    }
    for(int i=1;i<=n;i++) {cin>>v[i];minn=min(minn,v[i]);}
    if(minn==v[1]){
        int h;
        if(arr[n]%t!=0) h=arr[n]/t+1;
        else h=arr[n]/t;
        cout<<h*v[1];
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            int h;
            if((arr[i]-arr[j])%t==0) h=(arr[i]-arr[j])/t;
            else h=(arr[i]-arr[j])/t+1;
            dp[i]=min(dp[i],dp[j]+h*v[j]);
        }
    }
    for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
    return 0;
}