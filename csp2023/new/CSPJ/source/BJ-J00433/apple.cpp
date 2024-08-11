// 2023/10/21 09:50
// By Jerry1031
//freopen checked!

#include <iostream>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    int n;
    cin >> n;

    int t = n, ans1 = 0, ans2 = 0;
    bool LOCK = false;
    for(int day = 1; t; day++)
    {
        if(t % 3 == 1 && !LOCK)
        {
            ans2 = day;
            LOCK = true;
        }
        t = t - t / 3 - bool(t % 3);
        ans1++;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
