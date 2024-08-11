#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n,z,cnt,cnt1 = 0,cnt2;
    cin>>n;

    int a[n+5] = {0};
    z = n;
    if(n == 1 || n == 2 || n == 3)
    {
        return 0;
    }
    while(z>0)
    {
        cnt1++;
        cnt = 1;
        for(int i = cnt1;i <= n;i++)
        {
            if(a[i] == 0)
            {
                cnt--;
                if(cnt == 0)
                {
                    if(i == n) cnt2 = cnt1;
                    a[i] = 1;
                    cnt = 3;
                    z--;
                }
            }
        }
    }
    cout<<cnt1<<" "<<cnt2;
    return 0;
}
