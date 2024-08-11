#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int c, T, n, m, a[N];

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> c >> T;
    while(T --)
    {
        memset(a, 0, sizeof a);
        cin >> n >> m;
        for(int i = 1; i <= m; ++ i)
        {
            char op;
            cin >> op;
            if(op == 'T' || op == 'F' || op == 'U')
            {
                int x;
                cin >> x;
                if(op == 'T') a[x] = 1;
                else if(op == 'F') a[x] = 2;
                else a[x] = 3;
            }
            else if(op == '+' || op == '-')
            {
                int x, y;
                cin >> x >> y;
            }
        }
        int cnt = 0;
        if(c == 3 || c == 4)
        {
            for(int i = 1; i <= n; ++ i)
            {
                if(a[i] == 3) ++ cnt;
            }
            cout << cnt << endl;
            continue;
        }
    }
    return 0;
}