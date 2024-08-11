#include <bits/stdc++.h>

using namespace std;
const int N = 10, M = 6;

int b[N][M], a[M], n, ans;

bool valid(int a[M], int b[M])
{
    int l = M - 1, r = 0, cnt = 0;
    for(int i = 1; i < M; i++)
    {
        if(a[i] != b[i])
        {
            l = min(l, i);
            r = max(r, i);
            cnt++;
        }
    }
    if(r - l >= 2 || cnt == 0) return 0;
    if(cnt <= 1) return 1;
    else
    {
        int flag = 0;
        for(int j = 0; j < 10; j++)
        {
            int newl = (a[l] + j) % 10, newr = (a[r] + j) % 10;
            flag |= newl == b[l] && newr == b[r];
        }
        return flag;
    }
}

void dfs(int k)
{
    if(k == M)
    {
        int flag = 1;
        for(int i = 1; i <= n; i++)
        {
            flag &= valid(a, b[i]);
        }
        ans += flag;
        /*if(flag)
        {
            for(int j = 1; j < M; j++) printf("%d ", a[j]);
            puts("");
        }*/
        return;
    }
    for(int i = 0; i < 10; i++)
    {
        a[k] = i;
        dfs(k + 1);
    }
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < M; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
