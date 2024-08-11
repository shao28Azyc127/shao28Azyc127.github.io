#include <iostream>

using namespace std;
#define ll longlong
const int N=1e5+7;
int n,d;
ll ans;
int v[N],a[N];
int main()
{
    freopen("road1.in","r",stdin);
    freopen("tmp.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    ll pre=a[1],dis=0;
    for(inti=2;i<=n;i++){
    dis+=v[i];
    cout<<dis;
        return 0;
}
