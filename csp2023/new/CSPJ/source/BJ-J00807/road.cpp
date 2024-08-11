#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int a[10001]={};//jiangegonglishu
    int b[10001]={};//feiyong
    double c[10001]={};//jiangesuoxuyou
    int r;//need
    for(int i=0;i<m-1;i++)
    {
        cin>>a[i];
        r+=a[i];
        c[i]=a[i]/n;
    }
    int lag=0;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        if(b[0]<=b[i])
        {
            lag++;
        }
    }
    if(r%n==0)
    {
        r=r/n;
    }
    else
    {
        r=r/n+1;
    }
    if(lag==m)
    {
        cout<<b[0]*r<<endl;
        return 0;
    }
    int flag=0;
    int money;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i]<b[j])
            {
                c[i]+=c[j];
                flag++;
            }
            else
            {
                break;
            }
        }
        money+=(c[i]/1+1)*b[0];
        cout<<money<<endl;
        i+=flag;
        flag=0;
    }
    cout<<money<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

