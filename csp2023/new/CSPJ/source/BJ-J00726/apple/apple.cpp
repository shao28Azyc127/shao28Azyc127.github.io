#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w". stdout);
    long long n;
    cin >> n;
    long long t = n, cnt = 0, ans = 1;
    bool flag = true;
    while(t != 0)
    {
        if(t % 3 == 1 && flag == true)
        {
            ans = cnt + 1;
            flag = false;
        }
        int x = (t + 2) / 3;
        t -= x;
        cnt++;
    }
    cout << cnt << " ";
    if(n % 3 == 1) cout << 1;
    else cout << ans;
    return 0;
}
