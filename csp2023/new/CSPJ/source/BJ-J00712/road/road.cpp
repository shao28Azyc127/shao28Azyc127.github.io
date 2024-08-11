#include<iostream>
using namespace std;
#include<cstdio>
int n,m,l,mom,sp;
long long res;
int a[100005],b[100005],c[100005];
int main()
{
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
    cin>>n>>m;
    res=999999999;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {

        cin>>b[i];
        c[i]=b[i];
    }
    l=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(c[i]>c[j])
            {
                int s=c[i];
                c[i]=c[j];
                c[j]=s;
            }
        }
    }
    if(b[0]==c[0])
    {
        for(int i=0;i<n;i++)
        {
            sp=sp+a[i];
        }
        if(sp%m==0)
        {
            l=sp/m;
            mom=l*b[0];
        }
        else
        {
            l=sp/m+1;
            mom=l*b[0];
        }
        cout<<mom<<endl;
        fclose(stdin);
       fclose(stdout);
        return 0;

    }
     for(int i=0;i<1;i++)
    {
        sp=sp+a[i];
    }
    if(sp%m==0)
    {
        l=sp/m;
        mom=l*b[0];
    }
    else
    {
        l=sp/m+1;
        mom=l*b[0];
    }
    sp=0;
    for(int i=2;i<n;i++)
    {
        sp=sp+a[i];
    }
    if(sp%m==0)
    {
        l=sp/m;
        mom=mom+l*b[1];
    }
    else
    {
        l=sp/m+1;
        mom=mom+l*b[1];
    }
    cout<<mom<<endl;
    fclose(stdin);
    fclose(stdout);
     return 0;
}
