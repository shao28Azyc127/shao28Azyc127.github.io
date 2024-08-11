#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,a[100005],b[100005],minn=100009,left=0,money=0,road=0;
    cin>>n>>m;
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]<minn)
        {
            money+=ceil((road-left)*1.00/minn);
            left=money*min-road;
            minn=b[i];
            road=0;
        }
    }
    money+=ceil(road*1.00/minn);
    cout<<money;
    return 0;
}
