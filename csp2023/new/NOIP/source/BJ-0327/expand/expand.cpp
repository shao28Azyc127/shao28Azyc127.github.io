#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
const int INF=10000000000000000;
int n,m;
void to_min(int& x,int  y){if(x>y) x=y;}
struct Array{
    int c[N],spos[N],xpos[N];
    int findnext(int id){
        for(int i=id+1;i<=n;i++){
            if(c[i]>=c[id]) return i;
        }
        return -1ll;
    }
    int getmin(int l,int r){
        int  mn=INF;
        for(int i=l;i<=r;i++) to_min(mn,c[i]);
        return  mn;
    }
}a,b;
bool check1(){
    if(a.c[1]<=b.c[1]) return false;
    if(a.c[n]<=b.c[m]) return false;
    int cura=1,curb=1;
    while(cura<n){
        int posa=a.findnext(cura);
        //cerr<<cura<<" "<<posa<<endl;
        if(posa>0){
            int mn=a.getmin(cura,posa);
            while(curb<=m){
                if(b.c[curb]<mn) break;
                if(b.c[curb]>=a.c[cura]) return false;
                curb++;
            }
            if(curb>m) return false;
            cura=posa;
            continue;
        }
        else{
            int mpos=a.spos[cura],mn=a.c[mpos];
            int posb=m+1;
            for(int i=curb;i<=m;i++){
                if((i==m||b.c[b.spos[i+1]]>=mn)&&b.c[i]<mn){posb=i;break;}
            }
            /*
            int l=curb,r=m;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(b.c[b.spos[mid]]<mn) l=mid;
                else r=mid-1;
            }
            posb=l;
            */
            /*
            for(int i=m;i>=curb;i--){
                if(b.c[i]<mn){posb=i;break;}
                if(b.c[i]>=a.c[cura]) return false;
            }*/
            //cerr<<mpos<<" "<<mn<<" "<<posb<<" "<<m<<endl;
            if(posb==m+1) return false;
            for(int i=curb;i<=posb;i++)  if(b.c[i]>=a.c[cura])  return false;
            //cerr<<"..."<<endl;
            int xp=a.xpos[cura+1],x=a.c[xp];
            cura=xp;curb=posb;
        }
    }
    for(int i=curb;i<=m;i++)  if(b.c[i]>=a.c[cura]) return false;
    return true;
}
void init(int lim){
    a.spos[lim]=a.xpos[lim]=lim;
    for(int i=lim-1;i>=1;i--){
        if(a.c[i]<a.c[a.spos[i+1]]) a.spos[i]=i;
        else a.spos[i]=a.spos[i+1];
        if(a.c[i]>a.c[a.xpos[i+1]]) a.xpos[i]=i;
        else a.xpos[i]=a.xpos[i+1];
    }
    lim=n+m-lim;
    b.spos[lim]=b.xpos[lim]=lim;
    for(int i=lim-1;i>=1;i--){
        if(b.c[i]<b.c[b.spos[i+1]]) b.spos[i]=i;
        else b.spos[i]=b.spos[i+1];
        if(b.c[i]>b.c[b.xpos[i+1]]) b.xpos[i]=i;
        else b.xpos[i]=b.xpos[i+1];
    }
}
int C,q;
pair<int,int> pa[N],pb[N];
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%lld%lld%lld%lld",&C,&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%lld",&a.c[i]);
    for(int j=1;j<=m;j++) scanf("%lld",&b.c[j]);
    init(n);
    bool flag=check1();//cerr<<"!";
    for(int i=1,lim=max(n,m);i<=lim;i++) swap(a.c[i],b.c[i]),swap(a.spos[i],b.spos[i]),swap(a.xpos[i],b.xpos[i]);
    swap(n,m);
    flag|=check1();
    printf("%d",flag);
    for(int i=1,lim=max(n,m);i<=lim;i++) swap(a.c[i],b.c[i]),swap(a.spos[i],b.spos[i]),swap(a.xpos[i],b.xpos[i]);
    swap(n,m);
    while(q--){
        int kx,ky;scanf("%lld%lld",&kx,&ky);
        for(int i=1;i<=kx;i++){
            int p,v;scanf("%lld%lld",&p,&v);
            pa[i]={p,a.c[p]};
            a.c[p]=v;
        }
        for(int i=1;i<=ky;i++){
            int p,v;scanf("%lld%lld",&p,&v);
            pb[i]={p,b.c[p]};
            b.c[p]=v;
        }
        init(n);
        flag=check1();
        for(int i=1,lim=max(n,m);i<=lim;i++) swap(a.c[i],b.c[i]),swap(a.spos[i],b.spos[i]),swap(a.xpos[i],b.xpos[i]);
        swap(n,m);
        flag|=check1();
        printf("%d",flag);
        for(int i=1,lim=max(n,m);i<=lim;i++) swap(a.c[i],b.c[i]),swap(a.spos[i],b.spos[i]),swap(a.xpos[i],b.xpos[i]);
        swap(n,m);
        for(int i=1;i<=kx;i++) a.c[pa[i].first]=pa[i].second;
        for(int i=1;i<=ky;i++) b.c[pb[i].first]=pb[i].second;
        //cerr<<q<<endl;
    }
}
