#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int c,t,a[100205],to[100205],vs[100205],w[100205],f[100205],fl,s,as;
void dfs(int x,int p)
{
    if(vs[x]==0)
        s++;
    if(f[x]==1)
    {
        as+=s;
        fl=1;
        return;
    }
    if(vs[x]==1&&p==w[x])
        return;
    if(vs[x]==1&&p!=w[x])
    {
        as+=s;
        fl=1;
        f[x]=1;
        return;
    }
    vs[x]=1;
    if(a[x]>100000)
    {
        if(a[x]-100000=='U')
            as+=s;
        fl=1;
        f[x]=1;
        return;
    }
    if(a[x]==0)
        return;
    w[x]=p;
    if(a[x]>0)
        dfs(a[x],p);
    if(a[x]<0)
        dfs(-a[x],1-p);
    f[x]=fl;
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int i;
    cin>>c>>t;
    while(t--)
    {
        int n,m;
        memset(a,0,sizeof(a));
        memset(to,0,sizeof(to));
        memset(vs,0,sizeof(vs));
        memset(w,0,sizeof(w));
        memset(f,0,sizeof(f));
        as=0;
        cin>>n>>m;
        for(i=1;i<=m;i++)
        {
            char v;
            cin>>v;
            if(v>='A'&&v<='Z')
            {
                int x;
                cin>>x;
                if(a[x]!=0)
                    to[abs(a[x])]=0;
                a[x]=100000+v;
            }
            else if(v=='+')
            {
                int x1,x2;
                cin>>x1>>x2;
                if(a[x1]!=0)
                    to[abs(a[x1])]=0;
                to[x2]=x1;
                a[x1]=x2;
            }
            else
            {
                int x1,x2;
                cin>>x1>>x2;
                if(a[x1]!=0)
                    to[abs(a[x1])]=0;
                to[x2]=x1;
                a[x1]=-x2;
            }
        }
        for(i=1;i<=n;i++)
        {
            s=0;
            if(to[i]==0)
            {
                fl=0;
                dfs(i,0);
            }
        }
        fl=0;
        for(i=1;i<=n;i++)
        {
            s=0;
            if(vs[i]==0)
                dfs(i,0);
        }
        cout<<as<<endl;
    }
    return 0;
}
