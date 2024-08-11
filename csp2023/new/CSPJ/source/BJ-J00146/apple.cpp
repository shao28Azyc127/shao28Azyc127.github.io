#include <bits/stdc++.h>
using namespace std;
int n,cnt,nday;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n)
    {
        cnt++;
        if(!nday && n % 3 == 1) nday = cnt;
        int t = n / 3;
        if(n % 3 != 0) t++;
        n -= t;
    }
    cout << cnt << " " << nday;
    return 0;
}
