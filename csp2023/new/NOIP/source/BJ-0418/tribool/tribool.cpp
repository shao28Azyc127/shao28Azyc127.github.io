#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct A
{
    int f;
    int pos,num;
    int val;
};
A a[100010];
int n,m,ans=-1;
char c[110],v[110],k[110];
int x[110],y[110];
//U0 T1,F2;
int vis[100010],vqz[100010];
void dfs(int step,int sum)
{
    if(ans!=-1)return;
    if(step>n)
    {
        for(int i=1;i<=n;i++)k[i]=c[i];
        for(int i=1;i<=m;i++)
        {
            if(v[i]=='+')
            {
                k[x[i]]=k[y[i]];
            }
            else if(v[i]=='-')
            {
                if(k[y[i]]=='T')k[x[i]]='F';
                else if(k[y[i]]=='F')k[x[i]]='T';
                if(k[y[i]]=='U')k[x[i]]='U';
            }
            else k[x[i]]=v[i];

        }
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]!=k[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)ans=sum;
        return;
    }
    c[step]='T';
    dfs(step+1,sum);
    c[step]='F';
    dfs(step+1,sum);
    c[step]='U';
    dfs(step+1,sum+1);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--)
    {

        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            a[i].f=0;
            a[i].val=-1;
            a[i].pos=0;
            a[i].num=1;
        }
        if(C<=2)
        {
            for(int i=1;i<=m;i++)
            {
                cin>>v[i];
                if(v[i]=='+'||v[i]=='-')cin>>x[i]>>y[i];
                else cin>>x[i];

            }
            dfs(1,0);
            cout<<ans<<endl;
            ans=-1;
            continue;
        }
        for(int i=1;i<=m;i++)
        {
            char v;
            cin>>v;
            if(v=='+')
            {
                int x,y;
                cin>>x>>y;
                if(x==y)continue;
                if(a[y].f==0)
                {
                    if(a[y].val==-1)
                    {
                        a[x].val=10;
                        a[x].pos=y;
                        a[x].num=1;
                    }
                    else
                    {
                        a[x].val=10;
                        a[x].pos=y;
                        a[x].num=1;
                    }
                }
                else
                {
                    a[x].f=1;
                    a[x].val=a[y].val;

                }
            }
            else if(v=='-')
            {
                int x,y;
                cin>>x>>y;
                if(x==y)
                {
                    a[x].num=-a[x].num;
                }
                else if(a[y].f==0)
                {
                    if(a[y].val==-1)
                    {
                        a[x].val=10;
                        a[x].pos=y;
                        a[x].num=-1;
                    }
                    else
                    {
                        a[x].val=10;
                        a[x].pos=y;
                        a[x].num=-1;
                    }
                }
                else
                {
                    a[x].f=1;
                    if(a[y].val==1)a[x].val=2;
                    if(a[y].val==0)a[x].val=0;
                    if(a[y].val==2)a[x].val=1;
                }
            }
            else
            {
                int x;
                cin>>x;
                a[x].f=1;
                if(v=='T')
                {
                    a[x].val=1;
                }
                if(v=='U')
                {
                    a[x].val=0;
                }
                if(v=='F')
                {
                    a[x].val=2;
                }
            }
        }

        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].pos==0&&a[i].num==-1)
                a[i].val=0;
            if(a[i].val==10)
            {

                if(a[i].pos==i)
                {
                    if(a[i].num==1)a[i].val=-1;
                    else a[i].val=0;
                }
                else
                {
                    int ps=i;
                    bool f=0;
                    int cur=0;
                    while(a[ps].val==10)
                    {
                        //cout<<vis[ps]<<" ";
                        if(vis[ps]==i)
                        {
                            //cout<<1<<endl;
                            cur-=vqz[ps];
                            f=1;
                            break;
                        }
                        vqz[ps]=cur;
                        if(a[ps].num==-1)cur++;
                        vis[ps]=i;

                        ps=a[ps].pos;
                        //cout<<cur<<" ";
                    }
                    if(f==1)
                    {
                        if(cur%2==0)
                        {
                            for(int j=1;j<=n;j++)if(vis[j]==i)a[j].val=-1;
                        }
                        else for(int j=1;j<=n;j++)if(vis[j]==i)a[j].val=0;
                    }
                    else
                    {
                        if(vis[ps]==i)cur+=vqz[ps];
                        if(cur%2==0)a[i].val=a[ps].val;
                        else
                        {
                            if(a[ps].val==2)a[i].val=1;
                            else if(a[ps].val==1)a[i].val=2;
                            else if(a[ps].val==0)a[i].val=0;
                            else a[i].val=-1;

                        }
                    }
                    //cout<<ps<<" "<<a[ps].val<<endl;
                }

            }
            if(a[i].val==0)cnt++;
            //cout<<a[i].f<<" "<<a[i].val<<" "<<a[i].pos<<" "<<a[i].num<<endl;
        }
        cout<<cnt<<endl;
    }
    return 0;
}