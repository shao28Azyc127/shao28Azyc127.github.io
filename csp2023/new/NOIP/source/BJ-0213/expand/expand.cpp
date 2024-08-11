#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=5e5+10,inf=0x3f3f3f3f;

struct node{
    int k,p;
};
int c,n,m,a[N],b[N],x[N],y[N],q;
int kx,ky,px[N],py[N],vx[N],vy[N];
bool cmp(node xx,node yy){
    if(xx.k==yy.k) return xx.p<yy.p;
    return xx.k>yy.k;
}

node m_n(int x,int y){
    node z;
    z.k=x,z.p=y;
    return z;
}

void solve1(){
    node res[N];
    int cnt=0,l=1,r=1;
    res[l]=m_n(y[1],1);
    while(cnt<n){
        if(x[++cnt] > res[1].k){
            printf("0");
            return ;
        }
        l=lower_bound(res+1,res+l+1,m_n(x[cnt],1000),cmp)-res-1;
        r=res[l].p;
        while(y[r+1]>x[cnt]){
            l=upper_bound(res+1,res+l+1,m_n(y[++r],r),cmp)-res;
            res[l]=m_n(y[r],r);
        }
    }
    if(r>=m){
        printf("1");
    }
    else
        printf("0");
}

void solve2(){
    node res[N];
    int cnt=0,l=1,r=1;
    res[l]=m_n(x[1],1);
    while(cnt<m){
        if(y[++cnt] > res[1].k){
            printf("0");
            return ;
        }
        l=lower_bound(res+1,res+l+1,m_n(y[cnt],1000),cmp)-res-1;
        r=res[l].p;
        while(x[r+1]>y[cnt]){
            l=upper_bound(res+1,res+l+1,m_n(x[++r],r),cmp)-res;
            res[l]=m_n(x[r],r);
        }
    }
    if(r>=n){
        printf("1");
    }
    else
        printf("0");
}

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],x[i]=a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i],y[i]=b[i];
    if(x[1]<y[1]&&x[n]<y[n]) solve1();
    else if(x[1]>y[1]&&x[n]>y[n]) solve2();
    else{
        printf("0");
    }
    for(int i=1;i<=q;i++){
        cin>>kx>>ky;
        for(int j=1;j<=kx;j++){
            cin>>px[j]>>vx[j];
            x[px[j]]=vx[j];
        }
        for(int j=1;j<=ky;j++){
            cin>>py[j]>>vy[j];
            y[py[j]]=vy[j];
        }
        if(x[1]<y[1]&&x[n]<y[n]) solve1();
        else if(x[1]>y[1]&&x[n]>y[n]) solve2();
        else{
            printf("0");
        }
        for(int j=1;j<=kx;j++){
            x[px[j]]=a[px[j]];
        }
        for(int j=1;j<=ky;j++){
            y[py[j]]=b[py[j]];
        }
    }
    return 0;
}
