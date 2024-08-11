#include <bits/stdc++.h>
using namespace std;
int n,d;
int dis[100005],p[100005],sumdis[100005],mon;
double oil;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    sumdis[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>dis[i];
        sumdis[i]=sumdis[i-1]+dis[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    int numi=1;
    while(numi<n)
    {
        int sign=0,numj=0;
        for(int j=numi+1;j<=n;j++)
        {
            if(p[j]<p[numi])
            {
                mon=mon+p[numi]*ceil((sumdis[j]-sumdis[numi])*1.0/d-oil);
                oil=oil+ceil((sumdis[j]-sumdis[numi])*1.0/d-oil)-(sumdis[j]-sumdis[numi])*1.0/d;
                sign=1;
                numj=j;
                break;
            }
        }
        if(sign=1)
        {
            numi=numj;
        }
        else
        {
            numi++;
        }
    }
    cout<<mon;
    return 0;
}
