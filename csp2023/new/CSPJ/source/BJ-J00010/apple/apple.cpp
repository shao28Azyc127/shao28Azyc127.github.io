//90
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;

bool vis[1000010];
int ans, cnt, ansn;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        if(vis[i]) continue;
        ans++;
        int k = 3;
        for(int j = i;j <= n;j++)
        {
            if(!vis[j]) k++;
            else continue;
            if(k == 4)
            {
                k = 1;
                cnt++;
                vis[j] = 1;
                if(j == n) ansn = ans;
            }
        }
    }
    cout << ans << " " << ansn;
    return 0;
}
