#include<bits/stdc++.h>
using namespace std;
long long n,d;
long long a[100005],v[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    long long ch=a[1],sum=0,p=0;
    for(int i=1;i<n;i++)
    {
        sum-=v[i-1];
        if(a[i]<=ch) ch=a[i];
        if((v[i]-sum)%d==0)
        {
            long long s=(v[i]-sum)/d;
            sum+=s*d;
            p+=s*ch;
        }
        else
        {
            long long s=(v[i]-sum)/d+1;
            sum+=s*d;
            p+=s*ch;
        }
        //cout<<ch<<" test\n";
    }
    cout<<p;
    return 0;
}
