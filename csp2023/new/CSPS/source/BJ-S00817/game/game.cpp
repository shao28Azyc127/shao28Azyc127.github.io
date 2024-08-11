#include <bits/stdc++.h>
using namespace std;
string t;

pair<char, int> A[2000008];
int cnt = 0;
unordered_set<long long> K;

mt19937 P(random_device{}());
int main()
{
    freopen("game.in", "rb", stdin);
    freopen("game.out", "wb", stdout);
    int x;
    cin >> x >> t;
    if (x > 15008)
    {
        int64_t y = int64_t(x) * x / 3e7;
        for (int j = 0; j < x; j += P() % y)
        {
            cnt = 0;
            for (int i = j; i < x; ++i)
            {
                if (!cnt || A[cnt - 1].first != t[i])
                {
                    A[cnt++] = {t[i], i};
                }
                else
                {
                    K.insert((int64_t(i) << 32) + A[cnt - 1].second);
                    --cnt;
                    if(cnt == 0) {
                        K.insert((int64_t(i) << 32) + j);
                    }
                }
            }
        }
        cout << K.size();
        return 0;
    }
    for (int j = 0; j < x; ++j)
    {
        cnt = 0;
        for (int i = j; i < x; ++i)
        {
            if (!cnt || A[cnt - 1].first != t[i])
            {
                A[cnt++] = {t[i], i};
            }
            else
            {
                K.insert((int64_t(i) << 32) + A[cnt - 1].second);
                --cnt;
                if(cnt == 0) {
                    K.insert((int64_t(i) << 32) + j);
                }
            }
        }
    }
    cout << K.size();
    return 0;
}