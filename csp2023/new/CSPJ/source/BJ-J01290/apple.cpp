#include<iostream>
#include<cstdio>
using namespace std;

int n, cnt, ans;
bool flag;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    cin >> n;
    while(n > 0)
    {
        if(n % 3 == 1 && !flag)
        {
            flag = true;
            ans = cnt + 1;
        }

        cnt ++;
        if(n % 3 == 0) n -= n / 3;
        else
        {
            n -= (n / 3 + 1);
        }
    }

    cout << cnt << " " << ans << endl;

    return 0;
}
