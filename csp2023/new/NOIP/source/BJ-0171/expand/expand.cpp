#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int c,n,m,q,a[N],b[N],head1,tail1,head2,tail2;

long long tmax1[N*4],tmax2[N*4],tmin1[N*4],tmin2[N*4];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline void pushup1(int x){
    tmax1[x]=max(tmax1[ls(x)],tmax1[rs(x)]);
    tmin1[x]=min(tmin1[ls(x)],tmin1[rs(x)]);
}
inline void pushup2(int x){
    tmax2[x]=max(tmax2[ls(x)],tmax2[rs(x)]);
    tmin2[x]=min(tmin2[ls(x)],tmin2[rs(x)]);
}
void build1(int x,int l,int r){
    if(l==r){
        tmin1[x]=tmax1[x]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build1(ls(x),l,mid);
    build1(rs(x),mid+1,r);
    pushup1(x);
}
void update1(int x,int l,int r,int P,int K){
    if(l==r){
        tmin1[x]=tmax1[x]=K;
        return;
    }
    int mid=(l+r)>>1;
    if(P<=mid)update1(ls(x),l,mid,P,K);
    else update1(rs(x),mid+1,r,P,K);
    pushup1(x);
}
long long querymax1(){return tmax1[1];}
long long querymin1(){return tmin1[1];}
void build2(int x,int l,int r){
    if(l==r){
        tmin2[x]=tmax2[x]=b[l];
        return;
    }
    int mid=(l+r)>>1;
    build2(ls(x),l,mid);
    build2(rs(x),mid+1,r);
    pushup2(x);
}
void update2(int x,int l,int r,int P,int K){
    if(l==r){
        tmin2[x]=tmax2[x]=K;
        return;
    }
    int mid=(l+r)>>1;
    if(P<=mid)update2(ls(x),l,mid,P,K);
    else update2(rs(x),mid+1,r,P,K);
    pushup2(x);
}
long long querymax2(){return tmax2[1];}
long long querymin2(){return tmin2[1];}

int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    head1=a[1];
    tail1=a[n];
    head2=b[1];
    tail2=b[m];
    build1(1,1,n);
    build2(1,1,m);
    if(head1<head2&&tail1<tail2&&querymax1()<querymax2()&&querymin1()<querymin2())printf("1");
    else if(head1>head2&&tail1>tail2&&querymax1()>querymax2()&&querymin1()>querymin2())printf("1");
    else printf("0");
    while(q--){
        head1=a[1];
        tail1=a[n];
        head2=b[1];
        tail2=b[m];
        build1(1,1,n);
        build2(1,1,m);
        int k1,k2;
        scanf("%d%d",&k1,&k2);
        for(int i=1;i<=k1;i++){
            int p,v;
            scanf("%d%d",&p,&v);
            if(p==1)head1=v;
            if(p==n)tail1=v;
            update1(1,1,n,p,v);
        }
        for(int i=1;i<=k2;i++){
            int p,v;
            scanf("%d%d",&p,&v);
            if(p==1)head2=v;
            if(p==m)tail2=v;
            update2(1,1,m,p,v);
        }
        if(head1<head2&&tail1<tail2&&querymax1()<querymax2()&&querymin1()<querymin2())printf("1");
        else if(head1>head2&&tail1>tail2&&querymax1()>querymax2()&&querymin1()>querymin2())printf("1");
        else printf("0");
    }
    puts("");
    return 0;
}
//Workingmen of all countries, unite!