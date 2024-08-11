#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], b[100005], c[100005], head[100005], maxn=-1;
priority_queue<pair<long long,long long> > q;
struct{
    long long to, next;
}edge[100005];
long long f(long long p,long long date){
    long long tmp=a[p];
    while(tmp>0) tmp-=max(b[p]+date*c[p],1ll), date++;
    return date;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(long long i=1;i<=n-1;i++){
        long long u, v;
        scanf("%lld%lld",&u,&v);
        edge[i].to=v, edge[i].next=head[u], head[u]=i;
    }
    long long cur=1;
    for(long long i=1;i<=n;i++){
        maxn=max(maxn,f(cur,i));
        for(long long i=head[cur];i!=0;i=edge[i].next) q.push(make_pair(a[edge[i].to]/c[i],edge[i].to));
        pair<long long,long long> p=q.top();
        cur=p.second;
    }
    return printf("%lld",maxn)&0;
}