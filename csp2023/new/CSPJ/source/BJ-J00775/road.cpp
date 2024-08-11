#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int b[1000001];
int c[1000001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,ans,d,cnt=0;
    cin>>n>>d;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=a[i];
    }
    cnt=cnt/d;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++)
    {
        c[i]=b[i];
    }
    cout<<a[1]*cnt;
    return 0;
}
