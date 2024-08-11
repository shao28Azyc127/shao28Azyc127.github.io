#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int v[100005],a[100005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    long long ans = 0;
    long long sum = 0;
    cin >> n >> d;
    for(int i = 1;i < n;i++) cin >> v[i];
    for(int i = 1;i <= n;i++) cin >> a[i];
    int minn = 1e9;;
    for(int i = 1;i < n;i++)
    {
        minn = min(minn,a[i]);
        if(sum < v[i])
        {
            int k = (v[i]+d-sum-1)/d;
            sum += k*d;
            ans += k*minn;
            //cout << i << " " << k << " " << minn << " " << sum << endl;
        }
        sum -= v[i];
    }
    cout << ans << " ";
    return 0;
}
