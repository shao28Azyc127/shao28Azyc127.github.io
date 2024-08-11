#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
long long sum[maxn],a[maxn];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);
    for (int i=2;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        sum[i]=sum[i-1]+x;
    }
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);

    long long ans=0;
    int pos=0;
    for (int i=1;i<=n;i++){
        if (i==n) break;
        int j=i+1;
        while (j<n&&a[j]>=a[i]) j++;

        int I=sum[i]/d+(sum[i]%d!=0);
        int J=sum[j]/d+(sum[j]%d!=0);
        ans+=(J-I)*a[i];
        i=j-1;
    }

    printf("%lld\n",ans);
    return 0;
}