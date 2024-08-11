#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 8100;
char str[N];
int n, stk[N];
ll ans;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%s", &n, str + 1);
    for(int l = 1; l <= n; l++)
    {
        int top = 0;
        for(int i = l; i <= n; i++)
        {
            if(!top || str[stk[top]] != str[i]) stk[++top] = i;
            else top--;
            if(!top) ans++;
        }

    }
    printf("%lld\n", ans);
}
