#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 10010
ll v[maxn],a[maxn],n,m,cost=0;
ll length=0,station=1,from=0;
ll y=0;
void finds(ll s){
    station=s+1;
    length=v[s];
    while (station<n){
        if(a[station]>=a[s]){
            station++;length+=v[station];
        }
        else return ;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<n;i++)cin>>v[i];
    for(ll i=1;i<=n;i++)cin>>a[i];
    while (station<=n+1){
        from=station;
        finds(station);
        cost+=((length-y+m-1)/m)*a[from];
        y+=m-y-1;
    }
    cout<<cost;
    return 0;
}
