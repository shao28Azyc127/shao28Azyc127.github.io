#include <iostream>
#include <algorithm>
using namespace std;
int n,d;
struct oil
{
    int a1;
    int stopid;
    bool flag=false;
    int v;
}a[100010];
int minn=1e7;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int cnt=0;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i].v;
        cnt+=a[i].v;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].a1;
        a[i].stopid=i;
    }
    if(cnt%d==0) cnt/=d;
    else cnt+=(cnt/d+1);
    cout<<a[1].a1*cnt;
    return 0;
}