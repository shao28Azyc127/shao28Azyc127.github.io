#include<iostream>
using namespace std;
int n,d;
int v[1000000],w[1000000];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>w[i];
    int sum=0;
    for(int i=1;i<n;i++) sum+=v[i];
    cout<<sum*d*w[1];
    return 0;
}
