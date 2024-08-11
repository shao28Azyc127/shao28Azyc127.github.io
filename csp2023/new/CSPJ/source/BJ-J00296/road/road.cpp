#include <iostream>
using namespace std;
int v[100005],a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,i,m=10000000,s=0;
    cin>>n>>d;
    for(i=1;i<n;i++)
        cin>>v[i];
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        m=min(m,a[i]);
        if(v[i]<0)
        {
            v[i+1]+=v[i];
            continue;
        }
        if(v[i]%d==0)
        {
            s+=v[i]/d*m;
        }
        else
        {
            s+=(v[i]/d+1)*m;
            v[i+1]=v[i+1]-((v[i]/d+1)*d-v[i]);
        }
    }
    cout<<s;
    return 0;
}