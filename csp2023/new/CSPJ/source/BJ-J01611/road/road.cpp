#include<bits/stdc++.h>
using namespace std;
#define endl "\n";

int n, d, a[100005], c[100005], minn = 1e9;
long long ans, s;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minn = min(minn, a[i]);
    }
    if(minn == a[1])
    {
        long long sum;
        for(int i = 1; i <= n; i++)
            sum += c[i];
        if(sum % d == 0)
            cout << sum / d * a[1];
        else
            cout << (sum / d + 1) * a[1];
        return 0;
    }
    int i = 1;
    while(i <= n)
    {
        bool flag = 0;
        int cnt = 0, tmp = i;
        for(int j = i + 1; j <= n; j++)
        {
            if(a[i] > a[j])
            {
                for(int k = i; k < j; k++)
                    cnt += c[k];
                i = j;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            i++;
        cnt -= s;
        s = 0;
        if(cnt % d == 0)
            ans += cnt / d * a[tmp];
        else
        {
            s = (cnt / d + 1) *  d - cnt;
            ans += (cnt / d + 1) * a[tmp];
        }
    }
    cout << ans;
    return 0;
}
