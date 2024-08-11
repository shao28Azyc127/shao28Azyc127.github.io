#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,inf=1e9;
int n,d;
int v[N],a[N];
int f[N];

signed main(){


    //freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++)
        scanf("%lld",v+i);
    a[0]=inf;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        if(a[i]>a[i-1]) a[i]=a[i-1];
    }
    int ans=0;
    int dis=0;
    for(int i=1;i<n;i++){
            int cnt=0,t;
        if(dis<v[i]){
            t=v[i]-dis;
            cnt=t/d;
            if(cnt*d<t)cnt++;
            ans+=cnt*a[i];
            dis+=cnt*d;
        }
        dis-=v[i];
    }
    cout<<ans<<endl;
    return 0;
}
