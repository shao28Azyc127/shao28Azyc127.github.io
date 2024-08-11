#include<bits/stdc++.h>

using namespace std;

const int N=1e5+10;
typedef long long LL;

int n,d;
LL ans;
LL v[N],a[N];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;++i) scanf("%lld",&v[i]);
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
    LL minn=1e18,more=0;
    for(int i=1;i<n;++i){
        if(a[i]<minn){
            minn=a[i];
        }
        int f=min(v[i],more);
        v[i]-=f,more-=f;
        LL how=v[i]/d;
        if(v[i]%d) how++;
        ans+=how*minn;
        more+=how*d-v[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}