#include <bits/stdc++.h>
using namespace std;

int n, ans1, ans2;
bool flag = true;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(n)
    {
        ans1 ++;
        if(n % 3 == 1 && flag)
        {
            ans2 = ans1;
            flag = false;
        }
        n = n - ((n - 1) / 3 + 1);
    }
    cout << ans1 << " " << ans2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// 2 3  5 6
