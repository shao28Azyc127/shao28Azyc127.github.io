#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,d,sheng;
ll a[N],b[N],s[N];
ll ans=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        s[i+1]=s[i]+a[i];
    }
    for(int i=1;i<=n;i++) cin>>b[i];
    b[n]=0;
    ll L=1;
    while(L<n)
    {
        ll j,cur,cur1;
        for(j=L+1;j<=n;j++)
        {
            if(b[j]<b[L])
            {
                cur=s[j]-s[L];
                cur1=j;
                break;
            }
        }
        ans+=ceil(1.0*(cur-sheng)/d)*b[L];
        if((cur-sheng)%d!=0) sheng=d-(cur-sheng)%d;
        L=cur1;
    }
    cout<<ans;
    return 0;
}
