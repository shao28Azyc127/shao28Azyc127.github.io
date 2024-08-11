#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;

    for(int i = 1;i <= n-1;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        cin>>b[i];
    }
    int ans = 0;
    int minn = 1000000000;
    int x = 0;
    for(int i = 1;i <= n-1;i++)
    {
        if(b[i] < minn)
        {
            minn = b[i];
        }
        ans += ((minn-1) / d+1) * a[i];
    }
    cout<<ans;
    return 0;
}
