#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d,v[100005],a[100005],s[100005],cnt;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++)scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=2;i<=n;i++)s[i]=v[i-1]+s[i-1];
    for(int i=2;i<=n;i++){
        if(s[i]%d==0)s[i]/=d;
        else s[i]=s[i]/d+1;
    }
    ll zhun=a[1],st=1;
    for(int i=2;i<n;){
        while(zhun<=a[i]){
            i++;
            if(i==n)break;
        }
        ll nd=s[i]-s[st];
        cnt+=zhun*nd;
        zhun=a[i];st=i;
    }
    printf("%lld",cnt);
    return 0;
}
