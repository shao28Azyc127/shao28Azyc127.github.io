#include <iostream>
#include <algorithm>
using namespace std;
int n,d,v[10005],a[10005],b[10005],sum,sum2,sum3,q,ans,cnt = 1;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> v[i];
        sum2+=v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    q = b[1];
    sort(b+1, b+n+1);
    if (b[1]==q)
    {
        int num = 0;
        if (sum2 % d != 0)
        {
            num = sum2/d+1;
        }
        else{
            num = sum2/d;
        }
        cout << num*q;
    }
    else
    {
        while(sum < sum2)
        {
            if (a[cnt]<=a[cnt+1])
            {
                int w = 0;
                w=v[cnt]+v[cnt+1];
                sum3 += w;
                int s = sum3-sum;
                sum+=s;
                if (s%d == 0)
                {
                    ans += s/d*a[cnt];
                }
                else
                {
                    sum+=(s/d+1)*d-s;
                    ans += (s/d+1)*a[cnt];
                }
            }
            else
            {
                sum3 += v[cnt];
                int s = sum3-sum;
                sum += s;
                if (s%d==0)
                {
                    ans+=s/d*a[cnt];
                }
                else
                {
                    sum += (s/d+1)*d-s;
                    ans += (s/d+1)*a[cnt];
                }
            }
            int e = 0;
            for (int i = 1; i <= n-1; i++)
            {
                e+=v[i];
                if (sum < e)
                {
                    cnt = i;
                    break;
                }
                else if (sum == e)
                {
                    cnt = i+1;
                    break;
                }
            }
        }
        cout << ans;
    }
    return 0;
}
