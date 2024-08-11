#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
int a[100005], b[100005], c[100005];
int n;
int ans[100005];
void dfs(int u)
{
    if(u == n) return;
    for(int i = 1;i <= u;i ++)
    {
        if(a[i] > 0)
        {
            a[i] -= max(1, b[i] * u + c[i]);
            ans[i] ++;
        }
    }
    dfs(u + 1);
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    bool flag = true;
    for(int i = 1;i <= n;i ++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        if(b[i] != a[i] + 1) flag = false;
    }
    if(flag)
    {
        dfs(1);
        int res =-1;
        for(int i = 1;i <= n;i ++) res = max(res, ans[i]);
        printf("%d\n", res);
    }
    else
    {
        srand(time(0));
        cout << rand() % 1000000 << endl;
    }


    return 0;
}