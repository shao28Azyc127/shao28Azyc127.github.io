#include<bits/stdc++.h>
using namespace std;
int n,d,v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin)
    freopen("road.out","w",stdout)
    cin >> n >> d;
    int visum=0;
    for(int i = 0;i < n-1;i++)
    {
        cin >> v[i];
        visum+=v[i];
    }
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    cout<<ceil(visum/d)*a[0];
    return 0;
}
