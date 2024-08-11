/*you can do it*/
#include<bits/stdc++.h>
#define fr(ii,xx,yy) for(int ii=xx;ii<=yy;ii++)
#define rf(ii,xx,yy) for(int ii=xx;ii>=yy;ii--)
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define pt printf
inline void rd() {} template<typename T,typename...args>inline void rd(T&x,args&...y) {
    char ch;
    bool f=0;
    for(ch=getchar(); !isdigit(ch); ch=getchar())if(ch=='-')f=1;
    for(x=0; isdigit(ch); ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
    if(f)x=-x;
    rd(y...);
}
using namespace std;
const int N=1e6+33;
int c,n,m,q,X[N],Y[N];



bool flag=0;
template<typename Fn>
void dfs(int x,int y,Fn cmp) {
   // pt("dfs %d %d\n",x,y);
    if(flag)return;

    if(y==m+1) {
        if(x==n+1) {
            flag=1;
        }
        return;
    }
    fr(to,y,m) {
        bool all=1;
        fr(i,y,to) {
            if(!cmp(X[x],Y[i])) {
                all=0;
                break;
            }
        }
        if(all) {
            dfs(x+1,to,cmp);
            if(flag)return;
            dfs(x+1,to+1,cmp);
            if(flag)return;
        }
    }
}

bool check() {
    if(max(n,m)<=2) {
        return (X[1]<Y[1]&&X[n]<Y[m])||(X[1]>Y[1]&&X[n]>Y[m]);
    } else {
        if(max(n,m)<=6) {
            flag=0;
            dfs(1,1,less<int>());
            dfs(1,1,greater<int>());
            return flag;
        } else return (X[1]<Y[1]&&X[n]<Y[m])||(X[1]>Y[1]&&X[n]>Y[m]);
    }
}

int px[N],py[N];
int main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);

    rd(c,n,m,q);
    fr(i,1,n)rd(X[i]);
    fr(i,1,m)rd(Y[i]);
    pt("%d",check());
    while(q--){
        fr(i,1,n)px[i]=X[i];
        fr(i,1,m)py[i]=Y[i];
        int a,b,p,v;
        rd(a,b);

        fr(j,1,a) {
            rd(p,v);
            X[p]=v;
        }
        fr(j,1,b) {
            rd(p,v);
            Y[p]=v;
        }
        pt("%d",check());

       fr(i,1,n)X[i]=px[i];
        fr(i,1,m)Y[i]=py[i];



    }


    return 0;
}
