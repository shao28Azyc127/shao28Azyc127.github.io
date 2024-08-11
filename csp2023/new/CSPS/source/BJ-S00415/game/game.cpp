#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

const int N = 1e6 + 5;
int n, h[N], f[N], ans;
string s;


int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    cin >> s;
    s = "#" + s;
    for(register int i = 1;i <= n;i++)
    {
        stack <char> q;
        q.push(s[i]);
        int j = i - 1;
        for(;j >= 1;j--)
            if(s[j] == q.top())
            {
                q.pop();
                if(q.empty())
                    break;
            }
            else
                q.push(s[j]);
        h[i] = j;
    }
    for(register int i = 1;i <= n;i++)
    {
        if(h[i])
            f[i] = f[h[i] - 1] + 1;
        ans += f[i];
    }
    printf("%d", ans);
    return 0;
}
