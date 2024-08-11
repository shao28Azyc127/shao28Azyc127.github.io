#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node{
    ll x[6];
    bool operator<(const Node &p)const{
        for(ll i=1;i<=5;i++)
            if(x[i]<p.x[i]) return 1;
            else if(x[i]>p.x[i]) return 0;
        return 0;
    }
}a[10];
ll n,ans;
map<Node,ll> mark;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=5;j++) a[i].x[j]=read();
        for(ll j=1;j<=5;j++)
            for(ll k=1;k<=9;k++){
                Node p=a[i];
                p.x[j]=(p.x[j]+k)%10;mark[p]++;
            }
        for(ll j=1;j<=4;j++)
            for(ll k=1;k<=9;k++){
                Node p=a[i];
                p.x[j]=(p.x[j]+k)%10;p.x[j+1]=(p.x[j+1]+k)%10;
                mark[p]++;
            }
    }
    for(auto i=mark.begin();i!=mark.end();i++)
        if(i->second==n) ans++;
    printf("%lld\n",ans);
    return 0;
}