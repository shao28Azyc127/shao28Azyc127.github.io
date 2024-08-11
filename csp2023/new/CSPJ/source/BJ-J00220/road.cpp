#include<bits/stdc++.h>
using namespace std;
int v[114514];
int a[114514];
int sum[114514];
int dp[114514];//min cost from 1 to i station
int dp2[1005][1005];//dp[i][j]:min cost from 1 to i and left jL
int n,d;

int minn=0x7fffffff;
void dfs(int now,int oil,int cost){
    if(now==n+1){
        minn=min(minn,cost);
        return;
    }
    if(oil*d>=sum[now])dfs(now+1,oil,cost);
    for(int i=v[i+1]/d+(v[i+1]%d==0?0:1);i<=sum[n]/d;i++)
        dfs(now+1,oil+i,cost+i*a[now]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    bool flag1=true;
    bool flag2=true;

    cin>>n>>d;
    for(int i=2;i<=n;i++)cin>>v[i],sum[i]=sum[i-1]+v[i];
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=2;i<=n;i++)
        if(a[i]<a[1])flag1=false;
    for(int i=2;i<=n;i++)
        if(a[i]/d>0)flag2=false;

    if(flag1){
        int t=(sum[n])/d;
        if((sum[n])%d>1)t++;
        cout<<t*a[1];
    }else if(flag2){
        dp[1]=0;
        for(int i=2;i<=n;i++){
            int minn=0x7fffffff;
            for(int j=1;j<i;j++){
                int t=(sum[i]-sum[j-1])/d;
                if((sum[i]-sum[j-1])%d>1)t++;
                minn=min(minn,dp[j]+t*a[j]);
            }
            dp[i]=minn;
            //printf("i:%d  dp[i]:%d\n",i,dp[i]);
        }
        cout<<dp[n];
    }else{
        dfs(1,0,0);
        cout<<minn<<'\n';
    }
    return 0;
}
/*
5 4
10 10 10 10
9 8 9 6 5

*/
