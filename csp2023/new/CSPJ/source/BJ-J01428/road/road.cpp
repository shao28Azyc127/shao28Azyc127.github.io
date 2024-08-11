#include<bits/stdc++.h>
using namespace std;
int v[100005],a[100005],lespri[100005],pre[100005];
int tot=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++)
        cin>>v[i],pre[i]=pre[i-1]+v[i];
    int lesp=19198100;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<lesp&&i!=n)
            lesp=a[i],lespri[++tot]=i;
    }
    //for(int i=1;i<=tot;i++)
      //  cout<<lespri[i]<<" ";
    //cout<<endl;
    double oil=0;
    int pri=0;
    for(int ii=1;ii<=tot;ii++)
    {
        int j=lespri[ii+1]-1;
        if(ii==tot)
            j=n-1;
        int i=lespri[ii];
        //cout<<j<<endl;
        // i -> j
        int dis=pre[j]-pre[i-1];
        //cout<<"dis: "<<dis<<endl;
        double nedoil=1.0*dis/d;

            nedoil-=oil;
            oil=ceil(nedoil)-nedoil;
            nedoil=ceil(nedoil);
            pri+=nedoil*a[i];
            //cout<<"BUY OIL "<<nedoil<<" L AT "<<i<<"ROAD\n";
            //cout<<"LEFT "<<oil<<" L OIL\n";
    }
    cout<<pri;
}
