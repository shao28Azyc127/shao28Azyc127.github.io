#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
struct Stack{
    int loc,val;
}st[MAXN];
int n,d,top,a[MAXN],nxt[MAXN];
long long v[MAXN],ans,last;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=2;i<=n;i++){
        scanf("%lld",&v[i]);
        v[i]+=v[i-1];
    }
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        while(top&&st[top].val>a[i]){
            nxt[st[top].loc]=i;
            top--;
        }
        st[++top]=(Stack){i,a[i]};
    }
    while(top){
        nxt[st[top].loc]=n;
        top--;
    }
    for(int i=1;i<n;i=nxt[i]){
        long long dis=v[nxt[i]]-v[i]-last;
        long long cost=ceil(1.0*dis/d);
        last=cost*d-dis;
        ans+=cost*a[i];
    }
    printf("%lld",ans);
    return 0;
}
