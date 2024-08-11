#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 1e5+5;
#define int long long
int n,d,dist,last,ans;
int a[N],v[N];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i = 1;i<n;i++)
        cin>>v[i];
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    int k = 1;
    while(k<n)
    {
        int go = k;
        int sum = 0;
        while(go<n && a[go]>=a[k])
            sum += v[go++];
        sum -= last;
        int km = sum/d+(sum%d!=0);
        int price = km*a[k];
        ans += price;
        last = km*d-sum;
        k = go;
    }
    cout << ans << endl;
    return 0;
}
