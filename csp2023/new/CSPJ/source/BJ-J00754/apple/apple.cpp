#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int apple = n;
    int i = 0, ans = 0;
    while(apple)
    {
        if(apple % 3 == 1 && !ans) ans = i + 1;
        apple -= ceil(double(apple) / 3);
        i++;
    }
    cout << i << " " << ans;
    return 0;
}
