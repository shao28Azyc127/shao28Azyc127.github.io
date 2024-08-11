#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 0;
    int ans;
    bool flag = 0;
    while (n > 0)
    {
        if (n % 3 == 1 && flag == 0)
        {
            ans = cnt + 1;


            flag = 1;
        }
        int x = n / 3;
        int y = n % 3;
        if (y >= 1) x ++;
        n -= x;
        cnt ++;

    }
    cout <<cnt << " " << ans;
    return 0;
}