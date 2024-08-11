#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
long long read(){
    long long x=0,k=1;
    char c=getchar();
    for(;c!='-'&&(c>'9'||c<'0');c=getchar());
    if(c=='-') k=-1,c=getchar();
    for(;'0'<=c&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    return x*k;
}
int q;
struct T_node{
    int l,r;
    int mx,mn,pmx,pmn;
};
struct T{
    T_node t[2000006];
    int a[2000006];
    int n;
    int ls(int x){return x<<1;}
    int rs(int x){return x<<1|1;}
    void push_up(int now){
        if(t[ls(now)].mx>t[rs(now)].mx) t[now].mx=t[ls(now)].mx,t[now].pmx=t[ls(now)].pmx;
        else t[now].mx=t[rs(now)].mx,t[now].pmx=t[rs(now)].pmx;
        if(t[ls(now)].mn<t[rs(now)].mn) t[now].mn=t[ls(now)].mn,t[now].pmn=t[ls(now)].pmn;
        else t[now].mn=t[rs(now)].mn,t[now].pmn=t[rs(now)].pmn;
    }
    void build(int now,int l,int r){
        t[now].l=l,t[now].r=r;
        if(l==r){
            t[now].pmx=t[now].pmn=l;
            t[now].mx=t[now].mn=a[l];
            return;
        }
        int mid=l+r>>1;
        build(ls(now),l,mid),build(rs(now),mid+1,r);
        push_up(now);
    }
    void update(int now,int p,int x){
        if(t[now].l==t[now].r){
            t[now].mx=t[now].mn=a[p]=x;
            return;
        }
        int mid=t[now].l+t[now].r>>1;
        if(p<=mid) update(ls(now),p,x);
        else update(rs(now),p,x);
        push_up(now);
    }
    int get_mx(int now,int l,int r){
        if(l<=t[now].l&&t[now].r<=r) return t[now].pmx;
        int mid=t[now].l+t[now].r>>1;
        if(r<=mid) return get_mx(ls(now),l,r);
        if(l>mid) return get_mx(rs(now),l,r);
        int p1=get_mx(ls(now),l,r),p2=get_mx(rs(now),l,r);
        return a[p1]>a[p2]?p1:p2;
    }
    int get_mn(int now,int l,int r){
        if(l<=t[now].l&&t[now].r<=r) return t[now].pmn;
        int mid=t[now].l+t[now].r>>1;
        if(r<=mid) return get_mn(ls(now),l,r);
        if(l>mid) return get_mn(rs(now),l,r);
        int p1=get_mn(ls(now),l,r),p2=get_mn(rs(now),l,r);
        return a[p1]<a[p2]?p1:p2;
    }
    void init(){
        for(int i=1;i<=n;i++) a[i]=read();
        build(1,1,n);
    }
    // int get_lmx(int now,int x){
        
    // }
    int MX(){
        return a[get_mx(1,1,n)];
    }
    int MN(){
        return a[get_mn(1,1,n)];
    }
    // int mx_l(int r){
    //     return a[get_mx(1,1,r)];
    // }
    // int mx_r(int l){
    //     return a[get_mx(1,r,n))];
    // }
    
}t[2];
bool check_l(int mx,int r1,int r2){
    int mn=mx^1;
    if(r1>t[mx].n||r2>t[mn].n) return 1;
    
}
bool check_r(int mx,int l1,int l2){
    
}
int f[2003][2003];
bool check(){
    if((t[0].MN()<t[1].MN()&&t[0].MX()<t[1].MX()&&t[0].a[1]<t[1].a[1]&&t[0].a[t[0].n]<t[1].a[t[1].n])||
    (t[0].MN()>t[1].MN()&&t[0].MX()>t[1].MX()&&t[0].a[1]>t[1].a[1]&&t[0].a[t[0].n]>t[1].a[t[1].n]));
    else return 0;
    int mx=0;
    if(t[0].MX()<t[1].MX()) mx=1;
    int mn=mx^1;
    if(t[1].n<=2000&&t[0].n<=2000){
        for(int i=1;i<=t[mx].n;i++){
            for(int j=1;j<=t[mn].n;j++){
                if(t[mx].a[i]<=t[mn].a[j]){
                    f[i][j]=0;
                    continue;
                }
                if(i==1&&j==1) f[i][j]=1;
                else if(i==1) f[i][j]=f[i][j-1];
                else if(j==1) f[i][j]=f[i-1][j];
                else f[i][j]=f[i-1][j]|f[i][j-1];
            }
        }
        return f[t[mx].n][t[mn].n];
    }
    return 1;
    // int p1=t[mx].get_mx(1,1,t[mx].n),p2=t[mn]=get_mn(1,1,t[mn].n);
    // return check_l(mx,p1-1,p2-1)&&check_r(mx,p1+1,p2+1);
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int C=read();
    cin>>t[0].n>>t[1].n>>q;
    t[0].init(),t[1].init();
    putchar('0'+check());
    while(q--){
        // cout<<endl<<" "<<t[0].MN()<<" "<<t[0].MX()<<" "<<t[1].MN()<<" "<<t[1].MX()<<endl;
        int k1=read(),k2=read();
        vector<pair<int,int> > v0,v1;
        while(k1--){
            int x=read(),y=read();
            // cout<<x<<" "<<y<<endl;
            v0.push_back(make_pair(x,t[0].a[x]));
            t[0].update(1,x,y);
        }
        while(k2--){
            int x=read(),y=read();
            v1.push_back(make_pair(x,t[1].a[x]));
            t[1].update(1,x,y);
        }
        // cout<<endl<<" "<<t[0].MN()<<" "<<t[0].MX()<<" "<<t[1].MN()<<" "<<t[1].MX()<<endl;
        putchar('0'+check());
        for(int i=0;i<v0.size();i++){
            // cout<<v0[i].fir
            t[0].update(1,v0[i].first,v0[i].second);
        } 
        for(int i=0;i<v1.size();i++) t[1].update(1,v1[i].first,v1[i].second);
    }
    return 0;
}