#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c, n, m, q;
    cin >> c >> n >> m >> q;
    if(n == 1 && m == 1)
    {
        int x, y;
        cin >> x >> y;
        if(x != y) cout << 1;
        else cout << 0;
        for(int l = 1;l <= q;l++)
        {
            int a, b;
            cin >> a >> b;
            for(int j = 1;j <= a;j++)
            {
                cin >> x;
                cin >> x;
            }
            for(int j = 1;j <= b;j++)
            {
                cin >> y >> y;
            }
            if(x != y) cout << 1;
            else cout << 0;
        }
    }
    return 0;
}

