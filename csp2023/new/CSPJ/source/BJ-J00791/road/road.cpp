#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    long long n,i,maxn=100000000,d,cnt=0;
    long double rp=0.00;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int a[n],b[n+1];
    for(i=1;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    for(i=0;i<n;i++)
    {
        if(i<n-1)
        {
            while(rp*d<a[i+1])
            {
                rp++;
                cnt+=b[i];
            }
        }
        rp-=a[i+1]/d;
    }
    cout<<cnt+b[n-2];
    return 0;
}
