#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d,n,a[100005],b[100005],tmp;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(ll i=1;i<=n-1;i++) scanf("%lld",&a[i]),tmp+=a[i];
    for(ll i=1;i<=n;i++) scanf("%lld",&b[i]);
    if(tmp%d==0) tmp/=d;
    else tmp/=d,tmp++;
    printf("%lld",tmp*b[1]);
    return 0;
}