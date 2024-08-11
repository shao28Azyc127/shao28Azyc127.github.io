#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N][10],n; bool vis[N];
inline int read()
{
    int ss=0,ww=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') ww=-1; ch=getchar();}
    while(ch>='0' && ch<='9') ss=(ss<<1)+(ss<<3)+(ch^48),ch=getchar();
    return ss*ww;
}
int cal(int x,int y)
{
    if(x<1 || y>5) return 0;
    int res=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if((i-j+10)%10!=(a[k][x]-a[k][y]+10)%10 && i!=a[k][x] && j!=a[k][y]) break;
                if(i==a[k][x] && j==a[k][y]) break;
                if(k==n) res++; 
            }
        }
    }
    return res;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    n=read(); int x=0,y=0,pos,cnt;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++) a[i][j]=read();
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            pos=cnt=0;
            for(int k=1;k<=5;k++)
            {
                if(a[i][k]==a[j][k]) continue;
                if((pos && pos!=k-1) || cnt>=2) {puts("0"); return 0;}
                pos=k,cnt++;
            }
            if(cnt==2)
            {
                if(!x) x=pos-1,y=pos;
                else if((x==pos || x==pos-1) && !y) x=pos-1,y=pos;
                else if(x==pos-1 && y==pos) x=pos-1,y=pos;
                else {puts("0"); return 0;}
            }
            else if(cnt==1)
            {
                if(!x) x=pos;
                else if(x==pos-1) y=pos;
                else if(x==pos+1) x=pos,y=pos+1;
                else if(x!=pos) {puts("0"); return 0;}
            }
        }
    }
    if(!x) printf("%d",9*9);
    else if(!y)
    {
        cnt=0;
        for(int i=1;i<=n;i++) vis[a[i][x]]=1;
        for(int i=0;i<10;i++) cnt+=vis[i];
        if(x==1 || x==5) printf("%d",cal(x-1,x)+cal(x,x+1));
        else printf("%d",cal(x-1,x)+cal(x,x+1)-(10-cnt));
    }
    else printf("%d",cal(x,y));
    return 0;
}