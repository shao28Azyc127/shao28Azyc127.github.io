#include <iostream>
using namespace std;
const int N = 1e9 + 7;
bool a[N];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int num = n;
    int ans = 0, ans2 = 0;
    bool flag = false;
    while (num > 0)
    {
        ans++;
        if (num % 3 == 1 && !flag)
        {
            ans2 = ans;
            flag = true;
        }
        if (num % 3 == 1 || num % 3 == 0) num = num / 3 * 2;
        else num = num / 3 * 2 + 1;
    }
    cout << ans << " " << ans2 << endl;
    return 0;
}
