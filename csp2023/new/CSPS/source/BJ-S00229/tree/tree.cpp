#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int N = 1e5 + 10;

ll a[N];
ll b[N];
ll c[N];

int check(int i)
{
    ll h = 0;
    ll cnt = 0;
    while(h < a[i])
    {
        cnt++;
        h += max(b[i] + i * c[i],1ll);
    }
    return cnt;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
    for(int i = 1; i <= n - 1; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans,i + check(i) - 1);
    }
    cout << ans;
    return 0;
}
