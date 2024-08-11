#include<iostream>
#include<cstdio>
using namespace std;
int v[1000005],a[10000005],s[1000005],f[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n , d , sum , ans = 0, m = 0,mi = 1e9;
    cin >> n >>d;
    for(int i = 1;i < n;i++)
    {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    for(int i = 1;i<= n;i++)
    {
        cin >> a[i];
        mi = min(mi,a[i]);
    }
    if(mi == a[1])
    {
        ans = s[n - 1] / d * a[1];
        if(s[n - 1] % d != 0)ans += a[1];
        cout<<ans;
        return 0;
    }
    for(int i = 1;i <n;i++)
    {
        sum = 0;
        if(f[i] == 1)continue;
        for(int j = i + 1;j <=n;j++)
        {
            if(a[j] < a[i])
            {
                sum += s[j  - 1] - s[i - 1]  - m;
                //cout<<sum<<endl;
                break;
            }
            else f[j] = 1;

        }
        //cout<<sum<<endl;
        ans += (sum / d )* a[i];
        if(sum % d != 0)
        {
            ans += a[i];
            m = sum - ((sum / d)*d);
        }
        //cout<<ans<<endl;

    }
    cout<<ans;
    return 0;
}
