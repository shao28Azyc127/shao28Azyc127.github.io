#include<bits/stdc++.h>
#pragma GCC(2)
using namespace std;
int n;
char a[2000005];
long long cnt;
void shuang(int t)
{
    if(a[t] == a[t + 1] && a[t] != 'A')
    {
        cnt++;
        a[t] = 'A';
        a[t + 1] = 'A';
        if(a[t - 1] == 'A')
        {
            cnt++;
        }
    }
    for(int j = 1 ; j <= min(n - t , t) ; j++)
    {
        if(a[t - j] == a[t + j + 1] && a[t - j != 'A'])
        {
            a[t - j] = 'A';
            a[t + j + 1] = 'A';
            cnt++;
            if(a[t - j - 1] == 'A')
            {
                cnt++;
            }
        }
        else
        {

            break;
        }
    }
}
int main()
{
    freopen("game.in" , "r" , stdin);
    freopen("game.out" , "w" , stdout);
    cin >> n >> a;
    for(int i = 0 ; i < n ; i++)
    {
        shuang(i);
    }
    cout << cnt << endl;
    return 0;
}
