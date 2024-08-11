#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m,k;
int ml[maxn];
int to[maxn][2][maxn];
int cnt[maxn];
queue<int> q;
int minto(int a,int now)
{
    if(a<=now) return now;
    return ((a-now-1)/k+1)*k+now;
}
void dfs()
{
    q.push(1);
    while(!q.empty())
    {
        int qf=q.front();
        for(int i=0;i<cnt[qf];i++)
        {
            if(ml[to[qf][0][i]]>minto(to[qf][1][i],ml[qf]+1))
            {
                q.push(to[qf][0][i]);
                ml[to[qf][0][i]]=ml[qf]+1;
            }
        }
        q.pop();
    }
}
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int u,v,a;
        scanf("%d%d%d",&u,&v,&a);
        to[u][0][cnt[u]]=v;
        to[u][1][cnt[u]++]=a;
    }
    for(int i=2;i<=n;i++) ml[i]=INT_MAX;
    dfs();
    printf("%d",ml[n]);
    return 0;
}
