#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int c,t,n,m,K,d,a[25],x[N],y[N],v[N];
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    c=read();t=read();
    while(t--){
        n=read();m=read();K=read();d=read();int jr=0;
        for(int i=1;i<=m;i++) x[i]=read(),y[i]=read(),v[i]=read();
        for(int i=0;i<=(1<<n)-1;i++){
            int k=i,tot=0,cnt=0,sum=0,ans=0,res=0;
            memset(a,0,sizeof a);
            while(k) a[++tot]=k%2,k>>=1;
            for(int j=1;j<=tot;j++) sum+=a[j];
            for(int j=1;j<tot;j++)
                if(a[j]&&a[j+1]) cnt++;
                else ans=max(ans,cnt),cnt=0;
            if(a[tot]&&a[tot-1]) cnt++,ans=max(ans,cnt);
            ans=max(ans,1ll);
            if(ans>K) continue;
            res-=sum*d;
            for(int j=1;j<=m;j++){
                int flag=0;
                for(int l=x[j]-y[j]+1;l<=x[j];l++) 
                    if(!a[l]) {flag=1;break;}
                if(flag)continue;
                res+=v[j];
            }
            jr=max(jr,res);
        }
        printf("%lld\n",jr);
    }
    return 0;
}