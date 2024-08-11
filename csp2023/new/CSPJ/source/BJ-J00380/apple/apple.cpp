#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

int n;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    int x = n,cnt = 0;
    int ans = 0;
    while(x)
    {
        if(x % 3 == 1)
        {
            x -= x / 3 + 1;
            if(ans == 0)
                ans = cnt + 1;
        }
        else if(x % 3 == 2)
        {
            x -= x / 3 + 1;
        }
        else
        {
            x -= x / 3;
        }
        cnt++;
    }
    cout << cnt << ' ' << ans << endl;
    return 0;
}
