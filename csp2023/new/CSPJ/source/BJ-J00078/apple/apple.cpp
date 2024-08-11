#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n, a, i, ans;
    bool b=true;
    cin >> n;
    a=n;
    for(i=1;a!=0;i++)
    {
        if((a-1)%3==0&&b)
        {
            ans=i;
            b=false;
        }
        a-=(a-1)/3+1;
    }
    cout << i-1 << " " << ans;
    return 0;
}
