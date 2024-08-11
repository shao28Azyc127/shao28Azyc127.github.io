#include<iostream>
using namespace std;

int n;
int cnt, ans;
bool flag;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(n > 0)
    {
        cnt++;
        if(n % 3 == 1 && !flag)
        {
            ans = cnt;
            flag = 1;
        }
        n = n - 1 - (n - 1) / 3;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}
