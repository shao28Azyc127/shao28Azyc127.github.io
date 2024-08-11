#include <bits/stdc++.h>
using namespace std;
int n,tianshu,bushu=INT_MAX;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    while(n)
    {
        tianshu++;
        if ((n-1) % 3 == 0)
        {
            bushu = min(tianshu,bushu);
        }
        n -= (n-1) / 3 + 1;
    }
    printf("%d %d",tianshu,bushu);
    return 0;
}
