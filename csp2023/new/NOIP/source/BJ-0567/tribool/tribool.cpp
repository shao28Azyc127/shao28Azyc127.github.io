#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
int n,m;
int c,T;
char cur[N],load[N];
int tot,head[N],ver[N<<1],nxt[N<<1];
bool vis[N];
struct Queries
{
    int opt;
    int x,y;
}q[N];
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
void Task1()
{
    while(T--)
    {
        n=read(),m=read();
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            char opt;
            cin>>opt;
            int x=read();
            cur[x]=opt;
        }
        for(int i=1;i<=n;i++) ans+=(cur[i]=='U');
        printf("%d\n",ans);
    }
}
// int getfa(int x) {return (x==fa[x])?x:getfa(fa[x]);}
void Task2()
{
    while(T--)
    {
        n=read(),m=read();
        int ans=0;
        for(int i=1;i<=n;i++) cur[i]='T';
        for(int i=1;i<=m;i++)
        {
            char op;
            cin>>op;
            if(op=='U'||op=='T'||op=='F') 
            {
                int x=read();
                cur[x]=op;
            }
            else 
            {
                int x=read(),y=read();
                // add(x,y);
                cur[x]=cur[y];
            }
        }
        // int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(cur[i]=='U') ans++;
        }
        cout<<ans<<endl;
    }
}
int de[20],ans;
void decode(int p)
{
    int pos=0;
    while(p) {de[++pos]=p%3;p/=3;}
}
void Task0()
{
    //0:T 1:F 2:U
    //n=read(),m=read();
    while(T--)
    {
        ans=99999;
        n=read(),m=read();
        for(int i=1;i<=m;i++)
        {
            char op[5];
            cin>>op;
            // cout<<op[0]<<endl;
            if(op[0]=='U') q[i].opt=2;
            if(op[0]=='T') q[i].opt=0;
            if(op[0]=='F') q[i].opt=1;
            if(op[0]=='+') q[i].opt=3;
            if(!strcmp(op,"-")) q[i].opt=4;
            if(op[0]=='U'||op[0]=='T'||op[0]=='F') 
            {
                int x=read();
                q[i].x=x;
            }
            else 
            {
                int x=read(),y=read();
                q[i].x=x,q[i].y=y;
            }
            // cout<<q[i].opt<<endl;
        }
        for(int i=0;i<pow(3,n);i++)
        {
            decode(i);
            for(int j=1;j<=n;j++) 
            {
                if(de[j]==0) cur[j]='T',load[j]='T';
                if(de[j]==1) cur[j]='F',load[j]='F';
                if(de[j]==2) cur[j]='U',load[j]='U';
            }
            for(int j=1;j<=m;j++)
            {
                if(q[j].opt==0) cur[q[j].x]='T';
                else if(q[j].opt==1) cur[q[j].x]='F';
                else if(q[j].opt==2) cur[q[j].x]='U';
                else if(q[j].opt==3) cur[q[j].x]=cur[q[j].y];
                else
                {
                    // if(i==0) cout<<j<<endl;
                    if(cur[q[j].y]=='U') cur[q[j].x]='U';
                    else if(cur[q[j].y]=='F') cur[q[j].x]='T';
                    else cur[q[j].x]='F';
                }
            }
            bool flag=true;
            for(int j=1;j<=n;j++) if(cur[j]!=load[j]) flag=false;
            if(flag)
            {
                int cnt=0;
                // cout<<i<<endl;
                // for(int j=1;j<=n;j++) cout<<cur[j];
                // puts("");
                // for(int j=1;j<=n;j++) cout<<load[j];
                // puts("");
                
                for(int j=1;j<=n;j++) cnt+=(load[j]=='U');
                // cout<<cnt<<endl;
                ans=min(ans,cnt);
            }
        }
        printf("%d\n",ans);

    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    c=read(),T=read();
    if(c==1||c==2) Task0();
    if(c==3||c==4) Task1();
    if(c==5||c==6) Task2();
    return 0;
}
/*
1 3
3 3
©\ 2 1
©\ 3 2
+ 1 3
3 3
©\ 2 1
©\ 3 2
©\ 1 3
2 2
T 2
U 2
*/