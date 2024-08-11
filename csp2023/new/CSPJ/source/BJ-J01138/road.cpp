#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll v[N];
ll s[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ll n,d;
    ll sum=0;
    ll ans=0;
    ll x;
    ll mn=INT_MAX,mn2=INT_MAX-1,mni,mn2i;
    bool f=0;
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++)
    {
        scanf("%lld",&v[i]);
        s[i]=s[i-1]+v[i];
    }
    for(int i=1;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]<mn)
        {
            mn=a[i];
            mni=i;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]>=mn && a[i]<mn2 && i!=mni)
        {
            mn2=a[i];
            mn2i=i;
        }
    }
    cin>>x;
    //cout<<mni<<" "<<mn2i<<endl;
    for(int i=1;i<n;i++)
    {
        if(i==mni)
        {
            if(mni>mn2i)
            {
                ll z=s[n-1]-s[i-1];
                ll t=(((z-sum)%d==0)?(z-sum)/d:(z-sum)/d+1);
                //cout<<z<<" "<<t<<endl;
                ans+=t*a[i];
                sum+=t*d;
                //cout<<ans<<" "<<sum<<endl;
            }
            else
            {
                ll z=s[mn2i-1]-s[i-1];
                ll t=(((z-sum)%d==0)?(z-sum)/d:(z-sum)/d+1);
                //cout<<z<<" "<<t<<endl;
                ans+=t*a[i];
                sum+=t*d;
                //cout<<ans<<" "<<sum<<endl;
            }
        }
        else if(i==mn2i)
        {
            if(mn2i>mni)
            {
                ll z=s[n-1]-s[i-1];
                ll t=(((z-sum)%d==0)?(z-sum)/d:(z-sum)/d+1);
                //cout<<z<<" "<<t<<endl;
                ans+=t*a[i];
                sum+=t*d;
                //cout<<ans<<" "<<sum<<endl;
            }
            else
            {
                ll z=s[mni-1]-s[i-1];
                ll t=(((z-sum)%d==0)?(z-sum)/d:(z-sum)/d+1);
                //cout<<z<<" "<<t<<endl;
                ans+=t*a[i];
                sum+=t*d;
                //cout<<ans<<" "<<sum<<endl;
            }
        }
        else
        {
            if(sum<v[i])
            {
                ll z=(((v[i]-sum)%d==0)?(v[i]-sum)/d:(v[i]-sum)/d+1);
                //cout<<z<<endl;
                sum+=z*d;
                ans+=z*a[i];
                //cout<<ans<<" "<<sum<<endl;
            }
        }
        sum-=v[i];
        //cout<<sum<<endl;
    }
    cout<<ans<<endl;
	return 0;
}
