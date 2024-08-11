#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100005],b[100005],c[100005];
int u[100005],v[100005];
int n;
bool f[100005];
int m[100005];
int cnt = 0;

bool able()
{
    for(int i = 1;i <= n;i ++)
    {
        if(!f[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin>> a[i] >> b[i] >> c[i];
    }
    for(int i = 1;i < n; i ++)
    {
        cin >> u[i] >> v[i];
    }
    while(!able())
    {
        cnt++;
        for(int i = 1;i <= min(n,cnt);i++)
        {
            m[i] += max(1,b[i] + cnt * c[i]);
            if(m[i] >= a[i])
            {
                f[i] = 1;
            }
        }
    }
    cout << cnt;
    return 0;
}
