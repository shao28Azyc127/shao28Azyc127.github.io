#include<iostream>
using namespace std;
int n,d,ans,v,a;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>v;
        ans+=v;
    }
    cin>>a;
    for(int i=0;i<n-1;i++)cin>>v;
    cout<<(ans/d+bool(ans%d))*a<<"\n";
    return 0;
}