#include<bits/stdc++.h>
using namespace std;
int n,d,v[1000001],a[1000001],sum=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>v[i]>>a[i];
    }
    cin>>a[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]<v[j])
            {
                sum = sum+a[j];
            }
        }
        sum = sum+n+d;
    }
    cout<<sum;
    return 0;
}
