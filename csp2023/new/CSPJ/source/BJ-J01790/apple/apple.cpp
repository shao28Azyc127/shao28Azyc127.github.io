#include <bits/stdc++.h>
using namespace std;

int main()
{
        freopen("apple.in","r",stdin);
        freopen("apple.out","w",stdout);
        int n;
        cin >> n;
        int ans1 = 0;
        int ans2;
        int cnt1 = n;
        int flag = 0;
        while (cnt1 > 0)
        {
                ans1++;
                int a = cnt1;
                for (int i = 1; i <= cnt1;i++)
                {
                        if (i % 3 == 1)
                        {
                                if (i == cnt1)
                                {
                                        flag++;
                                        if (flag == 1) ans2 = ans1;
                                }
                                a--;
                        }
                }
                cnt1 = a;
        }
        cout << ans1 << " " << ans2;
        return 0;
}

