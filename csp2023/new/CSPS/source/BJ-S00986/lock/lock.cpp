#include <bits/stdc++.h>
#define il inline
using namespace std;
const int N=1e5+5;
int n,a[N][6],b[N],c[N],in[N],ck[N],pw[N],ans=0;
int m,d[N];
int x,y,z,cur;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);pw[0]=1;
    for(int i=1;i<5;++i) pw[i]=pw[i-1]*10;
    for(int i=1;i<=n;++i){
        x=0;
        for(int j=1;j<=5;++j)
            scanf("%d",&a[i][j]),x=x*10+a[i][j];
        b[i]=x;
    }
    for(int i=0;i<=N-5;++i){
        m=0;
        for(int j=1;j<=5;++j) c[j]=(i/pw[5-j])%10;
        for(int j=1;j<=5;++j){
            for(int k=1;k<=9;++k){
                x=i+((c[j]+k)%10-c[j])*pw[5-j];
                if(x>=0) d[++m]=x,ck[x]=1;
            }
        }
        for(int j=1;j<5;++j){
            for(int k=1;k<=9;++k){
                x=i+((c[j]+k)%10-c[j])*pw[5-j]+((c[j+1]+k)%10-c[j+1])*pw[4-j];
                if(x>=0) d[++m]=x,ck[x]=1;
            }
        }
        cur=1;
        for(int j=1;j<=n;++j) if(!ck[b[j]]) cur=0;
        if(cur) ++ans;
        for(int j=1;j<=m;++j) ck[d[j]]=0;
    }
    printf("%d",ans);
    return 0;
}
