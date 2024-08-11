#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int have;
int dis[100100];
int cost[100100];
int min_cost=100000,min_num,sum_dis,mi=100000;
//void dfs()
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        scanf("%d",&dis[i]);
        sum_dis+=dis[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&cost[i]);
        if(min_cost>cost[i])
        min_cost=cost[i],min_num=i;
    }
    if(min_num==1){
        ans=(sum_dis+m-1)/m*min_cost;
        cout<<ans;
        return 0;
    }
    for(int i=0;i<n-1;i++)
    {
        mi=min(mi,cost[i]);
        dis[i]-=have;
        if(dis[i]<0)have=abs(dis[i]);
        else {
            ans+=(dis[i]+m-1)/m+mi;
            have+=dis[i]-(dis[i]+m-1)/m*m;
        }
    }
    cout<<ans;
    return 0;
}
/*
@@@@@@@ @@@@@@@ @@@@@@  @@@@@@  @     @
@       @     @ @     @ @     @  @   @
@@@@@@@ @     @ @@@@@@  @@@@@@    @ @
      @ @     @ @   @   @   @      @
@@@@@@@ @@@@@@@ @    @  @    @     @
*/
