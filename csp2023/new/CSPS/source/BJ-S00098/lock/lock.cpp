#include <bits/stdc++.h>
using namespace std;
int n,a[10][6];
map <string , int> mp;
void dfs(int x)
{
    for(int i = 1;i <= 5;i++)
    {
        for(int j = 0;j <= 9;j++)
        {
            string s = "";
            if(a[x][i] == j) continue;
            for(int k = 1;k <= 5;k++)
            {
                if(k == i) s += (j + '0');
                else s += (a[x][k] + '0');
            }
            mp[s]++;
        }
    }
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 9;j++)
        {
            string s = "";
            a[x][i] += j,a[x][i + 1] += j;
            for(int k = 1;k <= 5;k++) s += ((a[x][k] % 10) + '0');
            a[x][i] -= j,a[x][i + 1] -= j;
            mp[s]++;
        }
    }
}
int process[6],ans;
void solve(int step)
{
    if(step > 5)
    {
        string s = "";
        for(int i = 1;i < step;i++) s += (process[i] + '0');
        if(mp[s] == n) ans++;
        return ;
    }
    for(int i = 0;i <= 9;i++)
    {
        process[step] = i;
        solve(step + 1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) for(int j = 1;j <= 5;j++) scanf("%d",&a[i][j]);
    for(int i = 1;i <= n;i++) dfs(i);
    solve(1);
    printf("%d",ans);
    return 0;
}
