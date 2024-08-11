#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int dq;
int cnt;
int ans1;
int ans2;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    cnt = n;
    while(cnt > 0)
    {
        dq = -1;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == 0)
            {
                dq++;
                dq %= 3;
            }
            if(dq == 0 && a[i] == 0)
            {
                if(i == n)
                {
                    ans2 = ans1 + 1;
                }
                a[i] = 1;
                cnt--;
            }
        }
        ans1++;
    }
    cout << ans1 << " " << ans2;
    return 0;
}
