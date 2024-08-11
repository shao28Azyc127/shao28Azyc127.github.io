#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,a[500005],b[500005],kx,px,vx,ky,py,vy;
int ans[500005],ta[500005],tb[500005],mxa,mxb,ind;
void calc(){
    mxa=0;
    mxb=0;
    for(int i=1;i<=n;i++)
        mxa=max(mxa,ta[i]);
    for(int i=1;i<=m;i++)
        mxb=max(mxb,tb[i]);
    if(ta[1]==tb[1]){
        ans[++ind]=0;
        return;
    }
    if(ta[1]>tb[1]){
        if(mxa>mxb&&ta[n]>tb[m])
            ans[++ind]=1;
        else
            ans[++ind]=0;
    }
    else{
        if(mxa<mxb&&ta[n]<tb[m])
            ans[++ind]=1;
        else
            ans[++ind]=0;
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        ta[i]=a[i];
    for(int i=1;i<=m;i++)
        tb[i]=b[i];
    calc();
    while(q--){
        for(int i=1;i<=n;i++)
            ta[i]=a[i];
        for(int i=1;i<=m;i++)
            tb[i]=b[i];
        scanf("%d%d",&kx,&ky);
        while(kx--){
            scanf("%d%d",&px,&vx);
            ta[px]=vx;
        }
        while(ky--){
            scanf("%d%d",&py,&vy);
            tb[py]=vy;
        }
        calc();
    }
    for(int i=1;i<=ind;i++)
        printf("%d",ans[i]);
    return 0;
}
