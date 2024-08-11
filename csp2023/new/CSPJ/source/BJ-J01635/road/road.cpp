#include<iostream>
using namespace std;
int d,n,v[1000000],a[1000000],sum,x;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
    }
    cout<<sum/d/x+1;
    retrun 0;
}