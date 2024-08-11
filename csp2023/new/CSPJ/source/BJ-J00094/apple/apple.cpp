#include <iostream>
using namespace std;

int n,ans,cnt;

int main()
{
    cin >> n;
    while(n > 0)
    {
        cnt++;
        for(int i = 1;i <= n;i += 3)
        {
            if(i == n && ans == 0) ans = cnt;
            n--;
            if(n == 0) break;
        }
    }
    cout << cnt << ' ' << ans << "\n";
    return 0;
}