#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,u[100020],a[100020],mi=100001,mz,zl=0;
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>u[i];
        zl+=u[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(mi>a[i])
        {
            mi=a[i];
            mz=i;
        }
    }
    if(mz==1)
    {
        cout<<zl/d*mi;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}