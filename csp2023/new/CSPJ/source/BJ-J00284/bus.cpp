#include <iostream>
#include <cstdio>
using namespace std;
int n,m,k;
bool b[10003][10003];
int aa[10003][10003];
bool visited[10003];
void dfs(int time,int x)
{
    if(x==n)
    {
        if(time%k==0)
        {
            cout << time;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==x)
        {
            continue;
        }
        if(b[x][i]&&aa[x][i]<=time&&!visited[i])
        {
            visited[i]=1;
            dfs(time+1,i);
            visited[i]=0;
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int u,v,a;
        cin >> u >> v >> a;
        b[u][v]=1;
        aa[u][v]=a;
    }
    dfs(k,1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
