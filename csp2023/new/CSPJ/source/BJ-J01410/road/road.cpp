#include<iostream>
using namespace std;

#define ll long long
const int maxn=1e5+10;
int mnpos,dis[maxn],cost[maxn],n,d;
ll ans,bag;

int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  cin>>n>>d;
  for(int i=2;i<=n;i++)cin>>dis[i];
  for(int i=1;i<=n;i++)cin>>cost[i];
  mnpos=1;
  for(int i=2;i<=n;i++){
    if(bag>=dis[i])bag-=dis[i];
    else{
      ll buy=(dis[i]-bag+d-1)/d;
      //cout<<"get "<<buy<<" from "<<mnpos<<endl;
      ans+=buy*cost[mnpos];
      bag+=buy*d-dis[i];
    }
    if(cost[i]<cost[mnpos])mnpos=i;
  }
  cout<<ans<<endl;
}