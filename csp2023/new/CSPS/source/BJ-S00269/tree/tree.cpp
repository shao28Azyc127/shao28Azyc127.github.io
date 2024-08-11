#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],b[MAXN],c[MAXN];
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    }
    int flag=0;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        if(v!=u+1)  flag=1;
    }
    if(flag==0){
        int ans=0;
        for(int i=1;i<=n;i++){
            int day=i;
            long long sum=0;
            while(1){
                if(b[i]+day*c[i]>=1)    sum+=b[i]+day*c[i];
                else sum++;
                if(sum>=a[i])   break;
                day++;
            }
            ans=max(ans,day);
        }
        printf("%lld",ans);
    }
    return 0;
}
