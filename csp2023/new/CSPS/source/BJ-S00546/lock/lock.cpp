#include<iostream>
using namespace std;
int a[15],b[15],c[15],d[15],e[15];
int n;
int ans=0;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
    }
    int w=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            w*=2;
        }
    }
    ans+=w;
    w=1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            w*=2;
        }
    }
    ans+=w;
    cout<<ans;
    return 0;
}
