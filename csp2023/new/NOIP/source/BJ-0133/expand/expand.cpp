#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int M=2005;
int op,n,m,q;
int a[N],b[N];
int c[N],d[N];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&op,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    if(op==1) printf("%d",(a[1]!=b[1]));
    else if(op==2) printf("%d",((a[1]>b[1]&&a[2]>b[2])||(a[1]<b[1]&&a[2]<b[2])));
    else printf("1");
    while(q--){
        for(int i=1;i<=n;i++) c[i]=a[i];
        for(int i=1;i<=m;i++) d[i]=b[i];
        int kx,ky;
        scanf("%d%d",&kx,&ky);
        for(int i=1;i<=kx;i++){
            int x,v;
            scanf("%d%d",&x,&v);
            c[x]=v;
        }
        for(int i=1;i<=ky;i++){
            int x,v;
            scanf("%d%d",&x,&v);
            d[x]=v;
        }
        if(op==1) printf("%d",(c[1]!=d[1]));
        else if(op==2) printf("%d",((c[1]>d[1]&&c[2]>d[2])||(c[1]<d[1]&&c[2]<d[2])));
        else printf("1");
    }
    return 0;
}
