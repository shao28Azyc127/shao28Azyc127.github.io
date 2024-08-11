#include <iostream>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll f[N],ff[N];
int main()
{
    ios::sync_with_stdio(0);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n;
    cin>>n;
    f[1]=1;
    //cout<<f[1]<<" ";
    for(ll i=2;i<=n;i++)
    {
        f[i]=f[i*2/3]+1;
        //cout<<f[i]<<" ";
    }
    ll cnt=0;
    while(!ff[n])
    {
        cnt++;
        ll res=2;
        for(ll i=1;i<=n;i++)
        {
            if(!ff[i])
                res++;
            if(res==3)
            {
                ff[i]=cnt;
                res=0;
            }
        }
    }
    /*
    for(ll i=1;i<=n;i++)
    {
        cout<<f[i]<<" "<<ff[i]<<endl;
    }
        */
    cout<<f[n]<<" "<<ff[n];
    return 0;
}
