/*you can do it*/
#include<bits/stdc++.h>
#define fr(ii,xx,yy) for(int ii=xx;ii<=yy;ii++)
#define rf(ii,xx,yy) for(int ii=xx;ii>=yy;ii--)
#define eb emplace_back
#define pii pair<int,int>
#define fi first
#define se second
#define pt printf
#define DB pt("666\n");
inline void rd() {} template<typename T,typename...args>inline void rd(T&x,args&...y) {
    char ch;
    bool f=0;
    for(ch=getchar(); !isdigit(ch); ch=getchar())if(ch=='-')f=1;
    for(x=0; isdigit(ch); ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
    if(f)x=-x;
    rd(y...);
}
using namespace std;
const int N=1e6+33,inf=2e9;
int qpow(int base,int exp) {
    int ret=1;
    while(exp) {
        if(exp&1)ret*=base;
        base*=base;
        exp>>=1;
    }
    return ret;
}
#define UU 2
#define TT 1
#define FF 0
int a[N],b[N],n,m;
char op[N];
namespace BF {
    int ori[N],x[N];
    int inv(int z) {
        if(z==UU)return UU;
        if(z==TT)return FF;
        if(z==FF)return TT;
    }
    void so() {
        int ans=inf;
        int Z=qpow(3,n)-1;
        fr(z,0,Z) {
            int cnt=0;
            bool vaild=1;
            fr(i,1,n) {
                x[i]=ori[i]=(z%qpow(3,i)/qpow(3,i-1));
                if(ori[i]==UU) {
                    cnt++;
                }
            }
            fr(i,1,m) {
                if(op[i]=='+') {
                    x[a[i]]=x[b[i]];
                } else if(op[i]=='-') {
                    x[a[i]]=inv(x[b[i]]);
                } else {
                    if(op[i]=='U')x[a[i]]=UU;
                    if(op[i]=='T')x[a[i]]=TT;
                    if(op[i]=='F')x[a[i]]=FF;
                }
            }
            if(equal(ori+1,ori+n+1,x+1,x+n+1)) {
                ans=min(ans,cnt);
            }
        }

        pt("%d\n",ans);
    }
}
namespace TFU {
    int x[N];
    void so() {
        fr(i,1,n)x[i]=TT;
        fr(i,1,m) {
            if(op[i]=='U')x[a[i]]=UU;
            if(op[i]=='T')x[a[i]]=TT;
            if(op[i]=='F')x[a[i]]=FF;
        }
        int cnt=0;
        fr(i,1,n) {
            if(x[i]==UU)cnt++;
        }
        pt("%d\n",cnt);
    }
} namespace UP {
    int v[N];
    int fa[2*N];
    vector<int> in[N];
    int Find(int x) {
        return x==fa[x]?x:fa[x]=Find(fa[x]);
    }
    void so() {
        iota(fa+1,fa+2*n+1,1);
        fr(i,1,n)fa[i]=n+i;
        fr(i,1,m) {
            if(op[i]=='U') {
                fa[a[i]]=0;
            }
            if(op[i]=='+') {
                fa[a[i]]=Find(b[i]);
            }
        }
        fr(i,1,n) {
            fa[n+i]=Find(i);
        }
        int cnt=0;
        fr(i,1,n) {
            if(Find(i)==0) {
                cnt++;
            }
        }
        pt("%d\n",cnt);
    }
} namespace NP {
    int v[N];
    int fa[2*N];
    int w[N];
    vector<int> in[N];
    int Find(int x) {
        if(x==fa[x]) {
            return fa[x];
        }
        int t=Find(fa[x]);
        fa[x]=t;
        (w[x]+=w[t])%=2;
        return fa[x];
    }
    void show(){
       // fr(i,1,n)pt("%d ",fa[i]);pt("fa\n");
        //fr(i,1,n)pt("%d ",w[i]);pt("w\n");
    }
    void Merge(int i,int j,int v) {
        int fx=Find(i);
        int fy=Find(j);
       // pt("M %d %d %d\n",i,j,v);
       // pt("fx%d fy%d wx%d wy%d",fx,fy,w[i],w[j]);
        if(fx==fy) {
            if((w[i]+v)%2!=w[j]) {
                  //  pt("E\n");

                fa[fx]=0;
                w[fx]=0;
            }
        } else {
            fa[i]=j;
            w[i]=v;
        }
    }
    void so() {
        iota(fa+1,fa+2*n+1,1);
        fr(i,1,2*n)w[i]=0;
        fr(i,1,n)fa[i]=n+i;
        show();

        fr(i,1,m) {
            if(op[i]=='-') {
                Merge(a[i],b[i],1);
            }
            if(op[i]=='+') {
                Merge(a[i],b[i],0);
            }
            show();
        }
        fr(i,1,n) {
            //fa[n+i]=Find(i);
            Merge(n+i,i,0);
        }
        int cnt=0;
        fr(i,1,n) {
            Find(i);
            if(fa[i]==0&&w[i]==1) {
                cnt++;
            }
        }
        pt("%d\n",cnt);
    }
}
int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T;
    rd(C,T);
    int Line=1;
    while(T--) {
        rd(n,m);
        fr(i,1,m) {
            char ee[4];
            scanf("%s",ee);
            op[i]=*ee;
            rd(a[i]);
            if(op[i]=='+'||op[i]=='-')rd(b[i]);
        }
        if(C<=2) {
            BF::so();
        } else if(C<=4) {
            TFU::so();
        } else if(C<=6) {
            UP::so();
        } else if(C<=8) {
            NP::so();
        }else UP::so();
    }

    return 0;
}
