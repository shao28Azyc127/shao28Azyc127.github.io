#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100002;

ll ans;
int n;
ll d;
ll v[MAXN];
ll a[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin >> n >> d;
    for(register int i = 1;i < n;i++)
        cin >> v[i];
    for(register int i = 1;i <= n;i++)
        cin >> a[i];
    
    int s = 0,sum = a[1];
    for(register int i = 1;i < n;i++)
    {
        if(a[s] > a[i] || i == 1)
        {
            if(sum < d) continue;
            if(sum % d == 0)
            {
                if(sum < d) continue;
                //cout << s << " " << sum / d << " " << a[s] << endl;
                ll t = sum / d;
                ans += t * a[s];
                sum = 0;
            }
            else
            {
                //cout << s << " " << sum / d + 1 << " " << a[s] << endl;
                ll t = sum / d + 1;
                ans += t * a[s];
                sum = -(sum % d);
            }

            s = i;
        }
        
        sum += v[i];
    }

    if(sum % d == 0)
        ans += (sum / d) * a[s];
    else
        ans += (sum / d + 1) * a[s];

    cout << ans << endl;
    return 0;
}