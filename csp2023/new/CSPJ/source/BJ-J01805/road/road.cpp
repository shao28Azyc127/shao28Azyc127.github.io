#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[100005];
int v[100005];
int a[100005];
int s[100005];

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    v[1] = 0;
    s[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    //memset(f,999999,sizeof(f));
    f[1] = 0;
    for(int i = 2;i <= n;i++)
    {
        int minn = 2e9;
        for(int j = 1;j < i;j++)
        {
            minn = min(minn,f[j] + (s[i] - s[j] + d - 1) / d * a[j]);
        }
        f[i] = minn;
    }
    cout << f[n] << endl;
    return 0;
}
