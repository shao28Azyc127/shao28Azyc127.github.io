#include <iostream>
#include <cstdio>
using namespace std;
int a[10000010],cnt,ccnt,ans,ans2;
long long n;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        a[i]=1;
    }
    while(cnt!=n)
    {
        ans++;
        ccnt=0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i])
            {
                if(ccnt==0)
                {
                    a[i]=0;
                    cnt++;
                    ccnt++;
                    if(i == n)
                    {
                        ans2 = ans;
                    }
                }
                else
                {
                    ccnt++;
                    if(ccnt >= 3)
                    {
                        ccnt=0;
                    }
                }
            }
        }
    }
    cout << ans << ' ' << ans2;
    return 0;
}
