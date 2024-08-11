#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct que{
    int op,a,b;
}Q[100005];
char op;
bool vis[100005];
int typ,T,n,m,tp,tx,tsol[100005];
void sol()
{
    int ans=0;
    while(T--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=m;i++)
        {
            cin>>op>>tx;
            if(op=='U')
                tsol[tx]=1;
            if(op=='T')
                tsol[tx]=2;
            if(op=='F')
                tsol[tx]=3;
        }//for(int i=1;i<=n;i++)cout<<tsol[i]<<" ";
        for(int i=1;i<=n;i++)
            if(tsol[i]==1)
                ans++;
        cout<<ans<<"\n";
    }
}
void sol2()
{
    int ans=0;
    while(T--)
    {
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=1;i<=m;i++)
        {
            cin>>op>>tp;
            if(op=='U')
                vis[tp]=true;
            if(op=='+')
            {
                cin>>tx;
                vis[tp]=vis[tx];
            }
        }
        for(int i=1;i<=n;i++)
            if(vis[i])
                ans++;
        cout<<ans<<"\n";
    }
}
int main()
{
    freopen("tribool.in" ,"r",stdin );
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>typ>>T;
    if(typ==3||typ==4)
    {
        sol();
        return 0;
    }
    if(typ==5||typ==6)
    {
        sol2();
        return 0;
    }
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
            cin>>op;
            if(op=='U'||op=='T'||op=='F')
            {
                cin>>tp;
                Q[i].op=1;
                Q[i].a=op;
                Q[i].b=tp;
            }
            if(op=='+')
            {
                cin>>tp>>tx;
                Q[i].op=2;
                Q[i].a=tx;
                Q[i].b=tp;
            }
            if(op=='-')
            {
                cin>>tp>>tx;
                Q[i].op=3;
                Q[i].a=tx;
                Q[i].b=tp;
            }
        }
    }
    return 0;
}