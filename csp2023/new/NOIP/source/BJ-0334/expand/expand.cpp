#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;

int c,n,m,q;
int a[N],b[N];

int check(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if((a[i]-b[i])*(a[j]-b[j])<=0)
                return 0;
    return 1;
}

signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);


    scanf("%lld%ll%lld%lld",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(int i=1;i<=m;i++)
        scanf("%lld",b+i);

    if(c<=2){
        printf("%lld",check());
        int kx,ky;
        int p,v;
        while(q--){
            scanf("%lld%lld",&kx,&ky);
            for(int i=1;i<=kx;i++){
                scanf("%lld%lld",&p,&v);
                a[p]=v;
            }
            for(int i=1;i<=ky;i++){
                scanf("%lld%lld",&p,&v);
                b[p]=v;
            }
            printf("%lld",check());
        }
        return 0;
    }


    return 0;
}
