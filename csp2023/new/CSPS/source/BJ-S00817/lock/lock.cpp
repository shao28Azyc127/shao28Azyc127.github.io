#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> T;

int main()
{
    freopen("lock.in", "rb", stdin);
    freopen("lock.out", "wb", stdout);

    int n;
    cin >> n;

    char a[5];
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < 5; ++k)
            cin >> a[k];
        char b[5];
        for (int k = 0; k < 5; ++k)
        {
            bcopy(a, b, 5);
            for (int i = 0; i < 9; ++i)
            {
                ++b[k];
                if (b[k] > '9')
                    b[k] -= 10;
                T[{b[0], b[1], b[2], b[3], b[4]}]++;
            }
        }
        for (int k = 0; k < 4; ++k)
        {
            bcopy(a, b, 5);
            for (int i = 0; i < 9; ++i)
            {
                ++b[k];
                ++b[k + 1];
                if (b[k] > '9')
                    b[k] -= 10;
                if (b[k + 1] > '9')
                    b[k + 1] -= 10;
                T[{b[0], b[1], b[2], b[3], b[4]}]++;
            }
        }
    }
    int ana = 0;
    for (auto&& k : T)
    {
        if (k.second == n)
            ++ana;
    }
    cout << ana;
}