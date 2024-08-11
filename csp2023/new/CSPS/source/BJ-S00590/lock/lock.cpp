#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[10][6],b[6],v[100005],s[100005],as;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int i,j,k,ii;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=5;j++)
        {
            cin>>a[i][j];
            b[j]=a[i][j];
        }
        for(j=1;j<=5;j++)
        {
            for(k=1;k<=9;k++)
            {
                b[j]=(a[i][j]+k)%10;
                int ss=0;
                for(ii=1;ii<=5;ii++)
                    ss=ss*10+b[ii];
                b[j]=a[i][j];
                if(v[ss]==0)
                    s[ss]++;
                v[ss]=1;
            }
        }
        for(j=1;j<=4;j++)
        {
            for(k=1;k<=9;k++)
            {
                b[j]=(a[i][j]+k)%10;
                b[j+1]=(a[i][j+1]+k)%10;
                int ss=0;
                for(ii=1;ii<=5;ii++)
                    ss=ss*10+b[ii];
                b[j]=a[i][j];
                b[j+1]=a[i][j+1];
                if(v[ss]==0)
                    s[ss]++;
                v[ss]=1;
            }
        }
        for(j=0;j<=99999;j++)
            v[j]=0;
    }
    for(i=0;i<=99999;i++)
        if(s[i]==n)
            as++;
    cout<<as;
    return 0;
}