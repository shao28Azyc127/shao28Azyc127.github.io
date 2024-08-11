#include <iostream>
#include <cstdio>
#define INF (int)(1e9)
#define MAXN 100050
using namespace std;
int n,m,testord;
char ct[20],ctmp[20];
int a[2*MAXN],fa[2*MAXN];
int ans=INF;

char v[MAXN];
int x[MAXN],y[MAXN];

int findfa(int pos)
{
    if (fa[pos]==pos) return pos;
    else return fa[pos]=findfa(fa[pos]);
}

void dfs(int pos)
{
    if (pos>n)
    {
        int tmp=0;
        for (int i=1;i<=n;i++)
        {
            ctmp[i]=ct[i];
            if (ct[i]=='U')
                tmp++;
        }
        //cout<<endl;
        if (tmp>ans)
            return ;
        for (int i=1;i<=m;i++)
        {
            if (v[i]=='T'||v[i]=='U'||v[i]=='F')
                ctmp[x[i]]=v[i];
            else if (v[i]=='+')
                ctmp[x[i]]=ctmp[y[i]];
            else
            {
                if (ctmp[y[i]]=='U') ctmp[x[i]]='U';
                else if (ctmp[y[i]]=='T') ctmp[x[i]]='F';
                else ctmp[x[i]]='T';
            }
        }
        int flag=1;
        for (int i=1;i<=n;i++)
        {
            if (ct[i]!=ctmp[i])
            {
                flag=0;
                break;
            }
        }
        if (flag)
        {
            ans=min(ans,tmp);
        }
    }
    else
    {
        ct[pos]='T';
        dfs(pos+1);
        ct[pos]='F';
        dfs(pos+1);
        ct[pos]='U';
        dfs(pos+1);
    }
    return ;
}

void solve()
{
    ans=INF;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>v[i];
        if (v[i]=='T'||v[i]=='U'||v[i]=='F')
            cin>>x[i];
        else
            cin>>x[i]>>y[i];
    }
    if (testord==7||testord==8)
    {
        for (int i=1;i<=2*n;i++)
        {
            fa[i]=i;
            a[i]=i;
        }
        for (int i=1;i<=m;i++)
        {
            if (v[i]=='+') a[x[i]]=a[y[i]];
            else a[x[i]]=(n+a[y[i]])%(2*n);
        }

        for (int i=1;i<=n;i++)
        {
            fa[findfa(i)]=findfa(a[i]);
        }

        int ban[MAXN],banp=0;
        int tmp=0;
        for (int i=1;i<=n;i++)
        {
            if (findfa(i)==findfa((n+i)%(2*n)))
            {
                ban[banp++]=findfa(i);
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<banp;j++)
            {
                if (findfa(i)==ban[j])
                {
                    tmp++;
                    continue;
                }
            }
        }
        cout<<tmp<<endl;
    }
    if (testord==5||testord==6)
    {
        for (int i=1;i<=n;i++)
            a[i]=0;
        for (int i=1;i<=m;i++)
        {
            if (v[i]=='U')
                a[x[i]]=1;
            else
                a[x[i]]=a[y[i]];
        }
        int tmp=0;
        for (int i=1;i<=n;i++)
            if (a[i])
                tmp++;
        cout<<tmp<<endl;
    }
    if (testord==3||testord==4)
    {
        for (int i=1;i<=n;i++)
            ct[i]='T';
        for (int i=1;i<=m;i++)
            ct[x[i]]=v[i];
        int tmp=0;
        for (int i=1;i<=n;i++)
            if (ct[i]=='U')
                tmp++;
        cout<<tmp<<endl;
    }
    if (testord==1||testord==2)
    {
        dfs(1);
        cout<<ans<<endl;
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int T;
    cin>>testord>>T;
    while (T--)
        solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
