#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d;
int v[100005],a[100005];
ll bsum[100005];
int next(int i){
    int x=a[i];
    while(i<n&&a[i]>=x) i++;
    return i;
}
ll Ceil(ll a,int b){
    if(a%b==0) return a/b;
    return a/b+1;
}
int main(){
    #ifndef JZQ
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    #endif
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n-1;i>=1;i--) bsum[i]=bsum[i+1]+v[i];
    int pos=1;
    ll cost=0,lst=0;
    while(pos<n){
        int npos=next(pos);
        ll dis=bsum[pos]-bsum[npos];
        ll add=Ceil(dis-lst,d);
        cost+=1ll*a[pos]*add;
        lst=(add*d+lst-dis)%d;
        pos=npos;
    }
    printf("%lld",cost);
    return 0;
}