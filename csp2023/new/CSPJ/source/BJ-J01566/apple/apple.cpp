#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    int ans=0;
    while(n)
    {
        n--;
        cnt++;
        if(ans==0 && n%3==0)
        {
            ans=cnt;
        }
        n-=n/3;
    }
    cout <<cnt << ' ' << ans <<endl;
    return 0;
}
