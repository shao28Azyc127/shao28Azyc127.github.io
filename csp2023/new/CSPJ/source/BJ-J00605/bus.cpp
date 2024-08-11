#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,maxx=-1,tot=1e7,ans=1e7;
ll up_qz(ll x,ll y){
    if(x%y==0)return x/y;
    else return x/y+1;
}
struct tu{
    ll b,e,v;
}a[1000005];//you xiang tu
struct node{
    ll x,time;
}ls;
queue<node>q;//guang sou queue
void bfs(){
    while(!q.empty()){
        node dt=q.front();
        q.pop();
        ll xx=dt.x,tt=dt.time;
        //cout<<xx<<" "<<tt<<endl;
        if(xx==n&&tt%k==0){
            tot=min(tot,tt);
            //cout<<"tot="<<tot<<endl;
        }
        for(ll i=1;i<=m;++i){
            //cout<<a[i].b<<" "<<a[i].e<<" "<<a[i].v<<endl;
            if(a[i].b==xx&&tt+1>=a[i].v){
                ls.x=a[i].e;ls.time=tt+1;
                q.push(ls);
            }
        }
    }
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    for(ll i=1;i<=m;++i){
        scanf("%lld %lld %lld",&a[i].b,&a[i].e,&a[i].v);
        maxx=max(maxx,a[i].v);
    }
    maxx=up_qz(maxx,k)*k;
    for(ll i=0;i<=maxx;i+=k){
        tot=0;
        //memset(book,0,sizeof(book));
        ls.x=1;ls.time=i;
        q.push(ls);
        bfs();
        //cout<<tot<<endl;
        if(tot!=1e7)ans=min(ans,tot);
        else ans=-1;
    }
    printf("%lld",ans);
    return 0;
}
