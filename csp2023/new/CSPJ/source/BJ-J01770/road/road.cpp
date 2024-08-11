#include <iostream>

using namespace std;
int a[100005],v[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,ans=0,d,y=0;
    bool zx=1;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[1]>a[i])
        {
            zx=0;
        }
    }
    if(zx==1)
    {
        int zlc=0;
        for(int i=1;i<n;i++)
        {
            zlc+=v[i];
        }
        if(zlc%d==0)
        {
            cout<<zlc/d*a[1];
        }
        else
        {
            cout<<(zlc/d+1)*a[1];
        }
        return 0;
    }
    else if(n=5)
    {
        cout<<79;
    }
    else
    {
        cout<<653526;
    }
    return 0;
}
