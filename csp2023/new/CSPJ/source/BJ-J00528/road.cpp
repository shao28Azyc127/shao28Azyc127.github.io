#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,d,tmp=2*maxn;
int v[maxn],a[maxn];
long long sum=0,cnt=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<n;i++)
        cin>>v[i];
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<n;i++)
    {
        tmp=min(tmp,a[i]);
        v[i]-=cnt;
        cnt=0;
        cnt+=d*(v[i]/d+(v[i]%d!=0))-v[i];
        sum+=tmp*(v[i]/d+(v[i]%d!=0));
    }
    cout<<sum;
    return 0;
}