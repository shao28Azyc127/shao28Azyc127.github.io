#include <iostream>
using namespace std;

int day(int id)
{
    if (id % 3 == 1) return 1;
    return day(id - (id + 2) / 3) + 1;
}

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, ans1 = 0;
    cin >> n;
    int ans2 = day(n);
    int cnt = n;
    while (cnt > 0)
    {
        cnt -= (cnt + 2) / 3;
        ans1++;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
