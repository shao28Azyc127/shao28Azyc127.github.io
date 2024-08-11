#include<iostream>
#include<cmath>
using namespace std;

int n;
int ans1,ans2;
bool flag = true;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while(n)
    {
        ans1++;
        if(n % 3 == 1 && flag)
        {
            flag = false;
            ans2 = ans1;
        }
        n -= ceil(1.0 * n / 3);
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}
