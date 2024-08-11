#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500010;
int c,n,m,q,a[MAXN],b[MAXN],aa[MAXN],bb[MAXN];
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    srand(clock());
    scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);aa[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&b[i]);bb[i]=b[i];
    }
    if((a[1]>b[1]&&a[n]<b[m])||(a[1]<b[1]&&a[n]>b[n])||(a[1]==b[1])||a[n]==b[n]){
        printf("0");
    }
    else {
        if(c==1||c==2){
            printf("1");
        }
        else printf("%lld",rand()%2);
    }
    while(q--){
        for(int i=1;i<=n;i++)a[i]=aa[i];
        for(int i=1;i<=m;i++)b[i]=bb[i];
        int kx,ky;
        scanf("%lld%lld",&kx,&ky);
        for(int i=1;i<=kx;i++){
            int p,u;
            scanf("%lld%lld",&p,&u);
            a[p]=u;
        }
        for(int i=1;i<=ky;i++){
            int p,u;
            scanf("%lld%lld",&p,&u);
            b[p]=u;
        }
        if((a[1]>b[1]&&a[n]<b[m])||(a[1]<b[1]&&a[n]>b[n])||(a[1]==b[1])||a[n]==b[n]){
            printf("0");
            continue;
        }
        if(c==1||c==2){
            printf("1");
            continue;
        }
        else{
            printf("%lld",rand()%2);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//lylakioi