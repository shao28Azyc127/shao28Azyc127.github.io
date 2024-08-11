#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main()
{
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
    long long n , cnt = 1 , ans = 0;
    bool flag = false;
    cin >> n;
    int temp = n;
    while(1)
    {
        int temp = n % 3 , t = n / 3 + 1;
        if(temp == 1 && flag == false)
        {
            ans = cnt;
            flag = true;
        }
        if(temp != 0) n = n - t;
        else n = n - t + 1;
        if(n == 0)
        {
            cout << cnt << " " << ans << endl;
            break;
        }
        cnt++;
    }
    return 0;
}
