#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;
int h[N],e[N],ne[N],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
struct Nd{
    ll a,b,c;
}p[N];
bool check(int mid){
    for(int i=1;i<=n;i++){
        if(p[i].c>=0){
            ll t=p[i].b*(mid-i+1)+p[i].c*(i+mid)*(mid-i+1)/2;
            if(t<p[i].a) return 0;
        }
        else{
            ll t=(1ll-p[i].b)/p[i].c;
            ll res=(i<=t?(t-i+1)*p[i].b+p[i].c*(t+i)*(t-i+1)/2+mid-t:mid-i+1);
            if(res<p[i].a) return 0;
        }
    }
    return 1;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);int u,v,w;
    for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
    bool flag=1;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        if(u!=i||v!=i+1) flag=0;
        add(u,v);add(v,u);
    }
    if(flag){
        int l=n,r=1e9,ans;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid)) r=mid-1,ans=mid;
            else l=mid+1;
        }
        printf("%d",ans);
    }
    return 0;
}
