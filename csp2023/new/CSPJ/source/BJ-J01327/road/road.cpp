#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
long long b[100005];
long long ans,z;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&b[i]);
    }
    for(int i=1;i<n;){
        int l=i+1;
        while(b[i]<b[l]){
            if(l>=n){
                break;
            }
            z+=a[l];
            ++l;
        }
        z+=a[l];
        ans+=(z/m)*b[i];
        z=z%m;
        if(z>0){
            z-=m;
            ans+=b[i];
        }
        i=l;
    }
    printf("%lld",ans);
    return 0;
}
