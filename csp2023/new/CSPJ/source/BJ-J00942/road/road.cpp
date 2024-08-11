#include<bits/stdc++.h>
using namespace std;
long long n,d,dis[100005],cost[100005],i=1,ans,last;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int b=1;b<n;b++){
        cin>>dis[b];
    }
    for(int b=1;b<=n;b++){
        cin>>cost[b];
    }
    while(i!=n){
        long long to=i+1,to_dis=0;
        while(to!=n && cost[to]>=cost[i]){
            to_dis=to_dis+dis[to-1];
            to++;
        }
        to_dis=to_dis+dis[to-1];
        ans=ans+(to_dis-last)/d*cost[i];
        if((to_dis-last)%d){
            ans=ans+cost[i];
            last=((to_dis-last)/d+1)*d-(to_dis-last);
        }else{
            last=0;
        }
        i=to;
    }
    cout<<ans;
    return 0;
}
