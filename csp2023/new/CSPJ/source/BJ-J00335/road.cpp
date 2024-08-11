#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int at[N],a[N],v[N],t[N],cnt=2;
unsigned long long ans=0,lastr=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    t[1]=1;
    int n,k;
    scanf("%d%d",&n,&k);
    a[1]=0;
    for(int i=1;i<n;i++) scanf("%d",&at[i]),a[i+1]=a[i]+at[i];
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        if(v[i]<v[t[cnt-1]]) t[cnt++]=i;
    }
    t[cnt]=n;
    for(int i=1;i<cnt;i++){
        int si=a[t[i+1]]-a[t[i]];
        ans+=ceil(1.0*(si-lastr)/k)*v[t[i]],lastr=lastr+ceil(1.0*(si-lastr)/k)*k-si;
        //printf("last=%d\n",lastr);
    }
    printf("%llu",ans);
    return 0;
}