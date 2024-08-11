#include<bits/stdc++.h>
using namespace std;
int n,m;
char op[100010];
int x[100010],y[100010];
int now[100010],lst[100010];
int llst[100010];
void upd()
{
    for(int i=1; i<=m; ++i)
    {
        if(op[i]=='+') now[x[i]]=now[y[i]];
        else if(op[i]=='-') now[x[i]]=2-now[y[i]];
        else now[x[i]]=(op[i]=='T'?0:op[i]=='U'?1:2);
    }
}
int ans;
void dfs(int wz)
{
    if(wz==n+1)
    {
        for(int i=1; i<=n; ++i) lst[i]=now[i];
        upd();
        bool flag=1; int cnt=0;
        for(int i=1; i<=n; ++i) flag&=(lst[i]==now[i]),cnt+=(lst[i]==1);
        if(flag) ans=min(ans,cnt);
        for(int i=1; i<=n; ++i) now[i]=lst[i];
        return;
    }
    now[wz]=0,dfs(wz+1),now[wz]=1,dfs(wz+1),now[wz]=2,dfs(wz+1);
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    int testid,t; cin>>testid>>t; while(t--)
    {
        cin>>n>>m;
        bool flag=1;
        for(int i=1; i<=n; ++i) llst[i]=0;
        for(int i=1; i<=m; ++i)
        {
            cin>>op[i];
            if(op[i]=='+' || op[i]=='-') cin>>x[i]>>y[i],flag=0;
            else cin>>x[i],llst[x[i]]=(op[i]=='T'?0:op[i]=='U'?1:2);
        }
        if(n<=10 && m<=10)
        {
            ans=1e9,dfs(1);
            cout<<ans<<'\n';
            continue;
        }
        else if(flag)
        {
            int cnt=0;
            for(int i=1; i<=n; ++i) cnt+=(llst[i]==1);
            cout<<cnt<<'\n';
            continue;
        }
        for(int i=1; i<=n; ++i) now[i]=0;
        upd();
        upd();
        upd();
        upd();
        for(int i=1; i<=n; ++i) lst[i]=now[i];
        upd();
        while(1)
        {
            bool flag=1;
            for(int i=1; i<=n; ++i)
            {
                if(now[i]!=lst[i]) now[i]=1,flag=0;
            }
            if(flag) break;
            for(int i=1; i<=n; ++i) lst[i]=now[i];
            upd();
        }
        int cnt=0;
        for(int i=1; i<=n; ++i) cnt+=(now[i]==1);
        cout<<cnt<<'\n';
    }
    return 0;
}
