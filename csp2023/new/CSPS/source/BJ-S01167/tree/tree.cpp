#include<bits/stdc++.h>
using namespace std;
int n,u,v,ans=0x7fffffff;
struct aa{
    int a,b,c,t=-1;
}mp[505];
bool nt[505][505];//lin jie ju zhen
void dfs(int d)
{
    if(d>10)
        return ;
    printf("day%d:\n",d);

    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        cout<<mp[i].t<<" ";
        if(mp[i].t<mp[i].a)
        {
            flag=1;
            break;
        }
    }
    if(!flag)//wan cheng ren wu
    {
        printf("finish on:%d\n",d);
        ans=min(ans,d);
        return ;
    }

    for(int i=1;i<=n;i++)
        if(mp[i].t!=-1)//yi zhi shu
            mp[i].t+=max(mp[i].b+d*mp[i].c,1);//wei hu t
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j&&nt[i][j]&&mp[j].t!=-1)//xvan ze zhi shu di kuai
            {
                mp[j].t=0;
                dfs(d+1);
                mp[j].t=-1;
            }
}
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&mp[i].a,&mp[i].b,&mp[i].c);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&u,&v);
        nt[u][v]=nt[v][u]=1;
    }
    mp[1].t=0;
    dfs(2);
    cout<<ans;
    return 0;
}
