#include<iostream>
#include<fstream>
using namespace std;
int n;
int c[15], d[15];
int a[15][15];
int ans = 0;
void check()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
            d[j] = c[j]-a[i][j];
        int cnt = 0;
        for(int j = 1; j <= 5; j++)
        {
            if(!d[j]) continue;
            cnt++;
            for(int k = 1; k <= j-2; k++)
            {
                if(d[k]) return;
            }
        }
        if(cnt > 2 || cnt == 0) return;
        if(cnt == 1) { continue; }
        for(int j = 1; j <= 5; j++)
        {
            if(d[j])
            {
                if((d[j]+10)%10 == (d[j+1]+10)%10) break;
                return;
            }
        }
    }
    ans++;
}
void dfs(int p)
{
    if(p > 5) return check();
    for(int i = 0; i <= 9; i++)
    {
        c[p] = i;
        dfs(p+1);
    }
}
int main()
{
    ifstream cin("lock.in");
    ofstream cout("lock.out");
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 5; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans;
    return 0;
}