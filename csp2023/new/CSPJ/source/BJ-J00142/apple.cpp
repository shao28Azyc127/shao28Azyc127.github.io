#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 0;
    bool flag = true;
    int ans;
    while(n > 0)
    {
        cnt++;
        if(n%3 != 0)
        {
            if(n % 3 == 1 && flag)
            {
                flag = false;
                ans = cnt;
            }
            n--;
        }
        n -= n/3;
        // cout <<n;
    }
    cout << cnt << " " << ans;
    return 0;
}
