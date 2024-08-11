#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll n,d;
ll v[N],a[N];
ll sa[N],sv[N];
ll ans = 0;
double oil = 0;
bool flag[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(ll i=1;i<n;++i)
    {
        cin >> v[i];
        sv[i] = sv[i-1] + v[i];
    }
    sv[n] = sv[n-1]+v[n-1];
    for(ll i=1;i<=n;++i)
    {
        cin >> a[i];
        sa[i] = sa[i-1] + a[i];
    }
    for(ll i=n-1;i>=1;--i)
    {
        if(a[i]<a[i-1])
        {
            flag[i] = 1;
        }
    }
    flag[1] = flag[n] = 1;
    for(ll i=1;i<n;++i)
    {
        if(!flag[i])
            continue;
        ll k;
        for(ll j=i+1;j<=n;++j)
        {
            if(flag[j])
            {
                k = j;
                break;
            }
            if(j==n-1)
                k = n-1;
        }
        //cout << i << " " << k <<" ";
        //cout << sv[k]-sv[i]<<endl;
        ll l = 0,r = (sv[k])/d-oil,mid;
        while(l<=r)
        {
            mid = l+r >> 1;
            //cout << "l,r,mid=" << l << " " <<r <<" " << mid<<endl;
            if((oil+mid)*d==sv[k]-sv[i])
            {
                //cout << mid;
                break;
            }
            else if((oil+mid)*d>sv[k]-sv[i])
                r = mid-1;
            else
                l = mid+1;
        }
        oil += mid;
        oil -= (sv[k]-sv[i])*1.0/d;
        ans += mid*a[i];
        //cout << "oil,ans" << oil << " " << ans <<endl;
    }
    cout << ans;
    return 0;
}
