#include<bits/stdc++.h>
#define FILE "run"
#define up(i,l,r) for(LL i=l; i<=r; i++)
#define dn(i,l,r) for(LL i=l; i>=r; i--)
using namespace std;

inline int read(){
    int f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return f*x;
}

typedef long long LL;
typedef unsigned long long ULL;
const int N=1e5+5;

LL P, T;
LL n,m,limit,cost;
struct rq{LL l,r,reward,il;}cl[N];

int main(){
    #ifdef FILE
    freopen(FILE".in","r",stdin);
    freopen(FILE".out","w",stdout);
    #endif // FILE
    P=read(),T=read();
    while(T--){
        n=read(),m=read(),limit=read(),cost=read();
        up(i,1,m){
            cl[i].r=read(),cl[i].l=cl[i].r-read()+1,cl[i].reward=read();
            if(cl[i].r-cl[i].l+1>limit||cl[i].l<1){i--,m--;}
        }
        if(P==17||P==18){
            LL sum=0;
            up(i,1,m){
                cl[i].reward-=(cl[i].r-cl[i].l+1)*cost;
                if(cl[i].reward>0) sum+=cl[i].reward;
            }
            printf("%lld\n",sum);
        }
        else{
            sort(cl+1,cl+1+m,[](rq a,rq b){return a.r!=b.r?a.r<b.r:a.l!=b.l?a.l<b.l:a.reward>b.reward;});
            up(i,1,m)printf("%lld,%lld,%lld\n",cl[i].l,cl[i].r,cl[i].reward);
            LL il=1,sum=0;
            up(i,1,m){
                sum+=cl[i].reward;
                while(cl[i].l>cl[il].l)sum-=cl[il].reward,il++;
                cl[i].reward=sum-(cl[i].r-cl[i].l+1)*cost;
                dn(j,il-1,1){
                    cl[i].il=j;
                    if(cl[j].r<cl[i].l)break;
                    if(cl[i].r-cl[j].l+1<=limit)break;
                }
            }
        }
    }
    return 0;
}
