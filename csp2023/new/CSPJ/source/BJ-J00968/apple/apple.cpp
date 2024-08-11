#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    long long ans = 1e18;
    long long n,t = 0;
    long long g = n;
    cin >> n;
    while(n != 0)
    {
        if(n % 3 == 1)
        {
            ans = min(ans,t + 1);
        }
        t++;
        n -= (n + 2) / 3;
    }
    cout << t  << " " << ans;
    return 0;
}
