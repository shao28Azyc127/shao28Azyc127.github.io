#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;

int n,d;
int v[N],a[N];
int pos = 1,ans;
int ld = 0;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1; i < n;i++)
    {
        cin >> v[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int pos = 1,ans = 0;
    while(pos != n)
    {
        int i = pos + 1;
        while(a[i] > a[pos] && i < n)
            i++;
        int dis = 0;
        for(int j = pos;j < i;j++)
            dis += v[j];
        int vv = ceil(1.0 * (dis - ld) / d);
        ans += vv * a[pos];
        ld = vv * d + ld - dis;
        pos = i;
    }
    cout << ans << endl;
    return 0;
}
