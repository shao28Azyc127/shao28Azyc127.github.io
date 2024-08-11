//road.cpp
#include <bits/stdc++.h>

using namespace std;
int n,d,v[200005],a[200005],sum[200005];
long long cst;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&v[i]);
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[n]=-1;
    int pos=a[1],curl=1;
    double sy=0.0;
    for(int i=2;i<=n;i++){
        if(a[i]<pos){
            double dst=sum[i-1]-sum[curl-1];
            double sydst=dst-sy*d;
            double ned=ceil(sydst*1.0/(d*1.0));
            cst+=ned*a[curl];
            sy=ned-sydst/d;
            pos=a[i];
            curl=i;
        }
    }
    printf("%lld\n",cst);
    return 0;
}
