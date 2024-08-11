#include<bits/stdc++.h>
using namespace std;
int n,cnt,tmp,minn,k;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>k;
    for(int i = 1;i<n;i++)
    {
        cin>>tmp;
        cnt+=tmp;
    }
    for(int i = 1;i<=n;i++)
    {
        cin>>tmp;
        minn = min(minn,tmp);
    }
    cout<<ceil(1.0*cnt/k)*minn;
    return 0;
}