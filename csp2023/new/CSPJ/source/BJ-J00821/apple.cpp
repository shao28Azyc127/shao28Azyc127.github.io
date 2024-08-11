#include <bits/stdc++.h>
using namespace std;

int n = 0, cnt = 0, ans = 0;
bool flag = 1;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;
    while(n != 0)
    {
        cnt++;
        if(n % 3 == 1 && flag)
        {
            ans = cnt;
            flag = 0;
        }
        n--;
        n -= (n / 3);
    }
    cout << cnt <<" "<<ans<<endl;
    return 0;
}