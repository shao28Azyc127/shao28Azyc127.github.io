#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,b;
    cin>>n>>b;
    int a[100001],q[100001];
    for(int i=0;i<n-1;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n;j++)
        cin>>q[j];
    }
    int s=0,t=0;
    for(int i=0;i<n-1;i++)
    {
        if((a[i]-t)%b==0) {
            s+=(a[i]-t)/b*q[i];
            t=0;
        }
        else
        {
            s+=(a[i]-t)/b*q[i]+q[i];
            t=((a[i]-t)/b+1)*b-a[i];
        }
    }
    cout<<s-b+1;
}