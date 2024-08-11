#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,m,a[200050],b[200050],k,num;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    k = b[1];
    for(int i=1;i<n;i++)
    {
        if(b[i]<k)
        {
            int e=0;
            e=num/m*k;
            num=num%m;
            if(num!=0)
            {
                num-=m;
                e+=k;
            }
            sum+=e;
            k=b[i];
        }
        num+=a[i];
    }
    int e=0;
    e=num/m*k;
    num=num%m;
    if(num!=0)
    {
        num-=m;
        e+=k;
    }
    sum+=e;
    cout<<sum;
    return 0;
}