#include <bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
const int N=2e6+5,M=26,T=1.5e7;
int n,pre[N],in[N];char s[N];ll ans;
int tree[N];
il void add(int x,int k){while(x<=n) tree[x]+=k,x+=(x&-x);}
il int get(int x){
    int ret=0;
    while(x) ret+=tree[x],x-=(x&-x);
    return ret;
}
int x,y,z,to,cur;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d%s",&n,s+1);
    int len=(n<=8000?n:T/n);
    for(int i=1;i<=n;++i){
        for(int j=0;j<M;++j) in[j]=0;
        cur=0,to=min(n,i+len);
        for(int j=i;j<=n && j-i<=len;++j){
            x=s[j]-'a';
            if(!in[x]) in[x]=j,add(j,1),++cur;
            else{
                add(j,-1),--cur,in[x]=0,y=get(j);
                if(!y && !cur) ++ans;
                if(!cur && y){to=j;break;}
            }
        }
        for(int j=0;j<M;++j) in[j]=0;
        for(int j=i;j<=to;++j){
            x=s[j]-'a';
            if(!in[x]) in[x]=j,add(j,-1);
            else add(j,1),in[x]=0;
        }
    }
    printf("%lld",ans);
    return 0;
}
