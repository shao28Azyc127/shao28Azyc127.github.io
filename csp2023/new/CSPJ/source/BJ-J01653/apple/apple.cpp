#include <bits/stdc++.h>
using namespace std;

typedef long long sll;
queue<int> q;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int bn = n;
    int cnt = 0;
    while (n >= 1)
    {
        if (n == 1)
        {
            break;
        }
        int vn = (n + 1) / 3;
        n = n - vn;
        cnt++;
    }

    if ((bn - 1) % 3 == 0)
    {
        cout << cnt << " ";
        cout << 1;
    }
    else
    {
        int nn = n;
        for (nn = n; nn >= 1; --nn)
        {
            if ((n + nn - 1) % 3 == 0)
            {
                cout << cnt << " " << (n + nn - 1) / 3;
                return 0;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
