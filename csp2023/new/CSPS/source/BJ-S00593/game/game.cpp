#include <bits/stdc++.h>
#define ll long long
using namespace std;
char a[1000005];
int n, l1, r1, cnt;
ll ans;
int l[1000005], r[1000005];
int l2[1000005], r2[1000005];
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    cin >> a + 1;
    for(int i = 2;i <= n;i++)
    {
       if(a[i] == a[i - 1])
       {
           l1 = i - 1;
           r1 = i;
           while(a[l1] == a[r1] && l1 > r[cnt])
           {
               l1 --;
               r1 ++;
           }
           cnt ++;
           if(l1 != r[cnt - 1])
           {
               l[cnt] = l1;
               r[cnt] = r1;
           }
           else
           {
               l[cnt] = l1 + 1;
               r[cnt] = r1 - 1;
           }
            ans += (r[cnt] - l[cnt] + 1)/2;
       }
    }
    int cnt1 = 0;
    bool ok = false;
    for(int i = 1;i <= cnt - 1;i ++)
    {
        if(l[i + 1] == r[i] + 1 && ok == false)
        {
            cnt1 ++;
            l2[cnt1] = i;
            r2[cnt1] = i + 1;
            ok = true;
        }
        if(l[i + 1] == r[i] + 1 && ok == true)
        {
            r2[cnt1] = i + 1;
        }
        else{
            ok = false;
        }
    }
    for(int i = 1;i <= cnt1;i ++)
    {
        ans += (r2[i] - l2[i] + 1)*(r2[i] - l2[i])/2;
    }
    printf("%lld", ans);
    return 0;
}
