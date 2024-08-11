#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
#define mp make_pair
#define pii pair<int, int>
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int n, res, top;
int st[N];
char s[N];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    n = read();
    scanf("%s", (s + 1));
    for (int l = 1; l <= n; l++)
    {
        top = 1;
        st[top] = s[l] - 'a';
        for (int r = l + 1; r <= n; r++)
        {
            if (top && s[r] - 'a' == st[top]) top--;
            else st[++top] = s[r] - 'a';
            if (top == 0) res++;
        }
    }
    printf("%d\n", res);
    return 0;
}