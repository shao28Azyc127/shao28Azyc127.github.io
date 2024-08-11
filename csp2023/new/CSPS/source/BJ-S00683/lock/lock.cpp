#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int maxn=100005;
int n,p[maxn],g[10],g_[10],ans;
const int pow10[10]={1,10,100,1000,10000};
int calc(){
    int res=0;
    for(int i=0;i<5;++i)res+=g_[i]*pow10[i];
    return res;
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        for(int i=0;i<5;++i)g[i]=read();
        for(int i=0;i<5;++i)for(int u=0;u<=9;++u)if(u!=g[i]){
            for(int j=0;j<5;++j)g_[j]=g[j];
            g_[i]=u;
            p[calc()]++;
        }
        for(int i=0;i<4;++i)for(int u=1;u<=9;++u){
            for(int j=0;j<5;++j)g_[j]=g[j];
            g_[i]=(g_[i]+u)%10;g_[i+1]=(g_[i+1]+u)%10;
            p[calc()]++;
        }
    }
    for(int i=0;i<100000;++i)if(p[i]==n)++ans;
    printf("%d",ans);
    return 0;
}