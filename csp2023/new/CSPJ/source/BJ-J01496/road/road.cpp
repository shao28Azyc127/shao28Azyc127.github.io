#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,d;
int v[N],a[N],s=1e9;
long long ans;
double fu;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d",&n,&d);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++)
    {
        s=min(s,a[i]);
        double len=1.0*v[i]/d;
        int need=ceil(len-fu);
        //printf("%lf %lf %d\n",len,fu,(int)ceil(len-fu));
        fu=fu+1.0*need-len;
        ans+=1ll*s*need;
    }
    printf("%lld",ans);
    return 0;
}
