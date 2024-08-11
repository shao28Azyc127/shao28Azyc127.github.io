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
const int maxn=2000005;
int n,nxt[maxn],st[maxn],bl[maxn],top;
char str[maxn];
long long ans;
void ct(int x){
    top=0;
    for(;x<=n;++x){
        if(top&&str[st[top]]==str[x]){
            nxt[st[top]]=x;
            top--;
        }
        else{
            if(nxt[x]!=-1){
                if(nxt[x]==0)break;
                x=nxt[x];
                continue;
            }
            st[++top]=x;
        }
        if(top==0)break;
    }
    for(int i=1;i<=top;++i)nxt[st[i]]=0;
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=read();
    scanf("%s",str+1);
    for(int i=1;i<=n;++i)nxt[i]=-1;
    for(int i=1;i<=n;++i)if(nxt[i]==-1)ct(i);
    for(int i=1;i<=n;++i)if(!bl[i]){
        int tmp=0;
        for(int j=i;j<=n;){
            bl[j]=1;
            j=nxt[j];
            if(!j)break;
            ++tmp;
            ++j;
        }
        //printf("%d %d\n",i,tmp);
        ans+=(long long)tmp*(tmp+1)/2;
    }
    printf("%lld",ans);
    return 0;
}