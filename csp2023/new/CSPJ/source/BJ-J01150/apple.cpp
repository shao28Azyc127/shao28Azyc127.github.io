#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, d = 0, all, ans2 = 0;
    cin>>n;
    all = n;
    while(all > 0)
    {
        d++;
        if(all % 3 == 1 && !ans2) ans2 = d;
        all -= (all + 2) / 3;
    }
    cout << d << ' ' << ans2 << endl;
    return 0;
}
