#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    if(n == 1) cout << 1 << " " << 1;
    else if(n == 2) cout << 2 << " " << 2;
    else
    {
        int ans1 = 0,ans2 = 0;
        while(n > 3)
        {
            if(n%3 == 1 && ans1 == 0) ans1 = ans2+1;
            n -= (n-1)/3+1;
            ans2++;
        }
        if(ans1 == 0) ans1 = ans2+n;
        cout << ans2+n << " " << ans1;
    }
    return 0;
}
