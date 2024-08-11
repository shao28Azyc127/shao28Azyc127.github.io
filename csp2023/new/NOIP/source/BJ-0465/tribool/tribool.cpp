#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,inf=0x3f3f3f3f;
struct node {int op,x,y;} q[N];
int tot,s[N],nw[N],n,m,ans;
inline int read()
{
    int S=0,W=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') W=-1; ch=getchar();}
    while(ch>='0' && ch<='9') S=(S<<1)+(S<<3)+(ch^48),ch=getchar();
    return S*W;
}
bool chk()
{
    for(int i=1;i<=n;i++) nw[i]=s[i];
    for(int i=1;i<=tot;i++)
    {
        if(q[i].op==1) nw[q[i].x]=nw[q[i].y];
        if(q[i].op==2) nw[q[i].x]=(3-nw[q[i].y])%3;
        if(q[i].op==3) nw[q[i].x]=q[i].y;
    }
    for(int i=1;i<=n;i++)
        if(s[i]!=nw[i]) return 0;
    // for(int i=1;i<=n;i++) cout<<s[i]<<" ";
    // cout<<endl;
    return 1;
}
void dfs(int x,int res)
{
    if(res>=ans) return;
    if(x==n+1)
    {
        if(chk()) ans=res;
        return;
    }
    s[x]=1; dfs(x+1,res);
    s[x]=2; dfs(x+1,res);
    s[x]=0; dfs(x+1,res+1);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c=read(),t=read();
    char op; int x,y;
    while(t--)
    {
        n=read(),m=read(); ans=inf,tot=0;
        for(int i=1;i<=m;i++)
        {
            op=getchar(),x=read();
            if(op=='+') y=read(),q[++tot]=(node){1,x,y};
            if(op=='-') y=read(),q[++tot]=(node){2,x,y};
            if(op=='T') q[++tot]=(node){3,x,1};
            if(op=='F') q[++tot]=(node){3,x,2};
            if(op=='U') q[++tot]=(node){3,x,0};
        }  
        if(c==3 || c==4)
        {
            chk(); ans=0;
            for(int i=1;i<=n;i++)
                if(!nw[i]) ans++;
            printf("%d\n",ans); continue;
        }
        else if(c<=2) {dfs(1,0); printf("%d\n",ans);}
        else puts("0");
    }
    return 0;
}