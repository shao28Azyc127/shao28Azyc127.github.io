#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,d,sum=0;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        int v;
        cin>>v;
        sum+=v;
    }
    int u;
    cin>>u;
    cout<<((sum-sum%d+d)/d)*u<<endl;
    for(int i=1;i<n;i++)
    {
        int v;
        cin>>v;
        sum+=v;
    }
    return 0;
}

