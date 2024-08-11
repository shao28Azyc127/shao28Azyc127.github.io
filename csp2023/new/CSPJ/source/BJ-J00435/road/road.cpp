#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("road.in","r",stdin);
    freopen ("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int v[n-1],a[n];
    for (int i=0;i<n-1;i++)
    {
        cin>>v[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    int lp=a[0];
    for(int k=0;k<n;k++)
    {
        if(a[k]<lp)
        {
            lp=a[k];
        }
    }
    if(lp=a[0])
    {
        int va=0;
        for (int l=0;l<n-1;l++)
        {
        va=va+v[l];
        }
        if(va%d!=0)
        {
            cout<<(va/d+1)*lp<<endl;
        }
        else
        {
            cout<<(va/d)*lp<<endl;
        }
    }
    else
    {
        int pa=0,va=0,ml=0,vn=0;
        int lp1=a[0];
        for (int m=0;m<n;m++)
        {
            if(a[m]<lp1)
            {
                for (int u=vn;u<m;u++)
                {
                    va=va+v[u];
                }
        if((va-ml)%d!=0)
        {
            pa=pa+((va-ml)/d+1)*lp1;
            ml=((va-ml)/d+1)*d-va;
        }
        else
        {
            pa=pa+((va-ml)/d)*lp1;
            ml=0;
        }
            lp1=a[m];
            vn=m;
            }
        }
        cout<<pa<<endl;
    }
    return 0;
}