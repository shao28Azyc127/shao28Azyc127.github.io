#include<iostream>
using namespace std;
int n,m,k,d,ans = -1;
int book[20001],z[20001],tail = 1;
int a[20001][20001];
void dfs(int s)
{
    if (s == n)
    {
        if ((tail-1) % k == 0 && ans == -1)
        {
            ans = tail-1;
        }
        else if ((tail-1) % k == 0 && (tail-1) % k < ans)
        {
            ans = tail-1;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (a[s][i] == 1)
        {
            z[tail] = s;
            tail++;
            book[s] = 1;
            dfs(i);
            tail--;
            book[s] = 0;
        }
    }
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin >> n >> m >> k;
    int v,u;
    for (int i = 1;i <= m;i++)
    {
        cin >> v >> u >> d;
        a[v][u] = 1;
    }
    dfs(1);
    cout << ans;
}
