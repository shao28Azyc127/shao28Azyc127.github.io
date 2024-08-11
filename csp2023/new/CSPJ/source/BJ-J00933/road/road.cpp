#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int n,d,v[maxn],a[maxn],cur=1,dis[maxn];
int st[maxn],top,mn[maxn],lst,ans;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=2;i<=n;i++){
        scanf("%lld",&v[i]);
        dis[i]=dis[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    a[n]=0;
    st[top=1]=n;
    for(int i=n-1;i>=1;i--){
        while(top&&a[st[top]]>a[i]) --top;
        mn[i]=st[top];
        st[++top]=i;
    }
    int pos=1;
    while(pos!=n){
        int nxt=mn[pos];
        int len=dis[nxt]-dis[pos]-lst;
        int num=len/d;
        if(len%d) ++num;
        lst=num*d-len;
        ans+=num*a[pos];
        pos=nxt;
    }
    printf("%lld",ans);
    return 0;
}
