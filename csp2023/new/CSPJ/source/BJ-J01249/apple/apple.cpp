#include<iostream>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans = 0,ans1 = 0,cnt = 0;
    cin >> n;
    long long a = n;
    while(n != 0)
    {
        ans = 0;
        for(long long i = 1;i <= n;i++)
        {
            if(i % 3 == 1)
            {
                ans++;
            }
            if(i == a && i % 3 == 1)
            {
                cnt = ans1 + 1;
            }
        }
        n -= ans;
        a -= ans;
        ans1++;
    }
    cout << ans1 << " " << cnt;
    return 0;
}
