#include <bits/stdc++.h>
using namespace std;

int n, ans1, ans2;
int main()
{
    ifstream cin("apple.in");
    ofstream cout("apple.out");
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; n; ++i)
    {
        ++ans1;
        if (!ans2 && n % 3 == 1)
        {
            ans2 = i;
        }
        n -= (n + 2) / 3;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}