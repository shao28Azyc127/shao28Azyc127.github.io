#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int C,n,m,q,a[N],b[N],c[N],d[N];
vector<int>E1,E2;
int getmax(int x,int l,int r){
    for(int i=l;i<=r;i++)if(b[i]>=x)return i-1;
    return r;
}
int remax(int x,int l,int r){
    for(int i=r;i>=l;i--)if(x>b[i])return i;
    return 0;
}
int getmin(int x,int l,int r){
    for(int i=l;i<=r;i++)if(b[i]<=x)return i-1;
    return r;
}
int remin(int x,int l,int r){
    for(int i=r;i>=l;i--)if(x<b[i])return i;
    return 0;
}
void getans(){
    int maxreach=0;
    if(a[1]==b[1]){printf("0");return ;}
    if(a[1]>b[1]){
        for(int i=1;i<=n;i++){
            int re=getmax(a[i],maxreach+1,m);
            if(re>maxreach){maxreach=re;continue;}
            re=remax(a[i],1,maxreach);
            if(re==0){printf("0");return ;}
            maxreach=re;
        }
        if(maxreach==m)printf("1");
        else printf("0");
        return ;
    }
    for(int i=1;i<=n;i++){
        int re=getmin(a[i],maxreach+1,m);
        if(re>maxreach){maxreach=re;continue;}
        re=remin(a[i],1,maxreach);
        if(re==0){printf("0");return ;}
        maxreach=re;
    }
    if(maxreach==m)printf("1");
    else printf("0");
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&C,&n,&m,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    getans();
    while(q--){
        int kx,ky;scanf("%d%d",&kx,&ky);
        E1.clear();E2.clear();
        for(int i=1;i<=kx;i++){
            int u,v;scanf("%d%d",&u,&v);
            c[u]=a[u];E1.push_back(u);
            a[u]=v;
        }
        for(int i=1;i<=ky;i++){
            int u,v;scanf("%d%d",&u,&v);
            d[u]=b[u];E2.push_back(u);
            b[u]=v;
        }
        getans();
        for(int i:E1)a[i]=c[i];
        for(int i:E2)b[i]=d[i];
    }
    return 0;
}
