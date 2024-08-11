#include <iostream>
using namespace std;
#define int long long
int n;
int ans1;
int ans2;
signed main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);
    while(n>0)
    {
        if(n%3==0)
            n-=n/3;
        else if(n%3==1)
        {
            if(ans2==0)
                ans2=ans1+1;
            n-=n/3+1;
        }
        else if(n%3==2)
            n-=n/3+1;
        ans1++;
    }
    printf("%lld %lld",ans1,ans2);
    return 0;
}
