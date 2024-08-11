#include<bits/stdc++.h>
#define N 100010
using namespace std;
int n,d;
int dis[N];
int cost[N];
int mincost[N];
int temp;
long long ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=(n-1);i++){
        cin>>dis[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    mincost[1]=cost[1];
    for(int i=2;i<=n;i++){
        mincost[i]=min(mincost[i-1],cost[i]);
    }


    for(int i=1;i<n;i++){
        if(dis[i]<=temp){
            temp=temp-dis[i];
            continue;
        }
        int num=((dis[i]-temp-1)/d)+1;
        ans+=num*mincost[i];
        temp=(num*d+temp)-dis[i];
    }
    cout<<ans;
    return 0;
}
