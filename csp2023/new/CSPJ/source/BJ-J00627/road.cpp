#include<iostream>
#include<cmath>
using namespace std;
const int N=100010;
int v[N],a[N];
int main()
{
    //f[i][j]
    //f[i][0]=min(f[])
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    long long sum=0;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<ceil(sum/d)*a[1];
    return 0;
}