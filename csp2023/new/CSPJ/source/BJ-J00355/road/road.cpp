#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long v[100050],a[100050];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++) {scanf("%lld",&v[i]);}
    for(int i=1;i<=n;i++) {scanf("%lld",&a[i]);}
    long long now=a[1],al=0,ans=0;
    for(int i=1;i<n;i++){
        now=min(now,a[i]);
        ans+=((v[i]-al+d-1)/d)*now;
        al=((v[i]-al+d-1)/d)*d-(v[i]-al);
    }printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
