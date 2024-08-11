#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10],ans,p[10],b[10];
int is[100010][6];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    p[1]=10000;
    for(int i=2;i<=5;i++)
    {
        p[i]=p[i-1]/10;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            b[j]=a[i][j];
        }
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=9;k++)
            {
                b[j]=(b[j]+k)%10;
                int sum=b[1]*p[1]+b[2]*p[2]+b[3]*p[3]+b[4]*p[4]+b[5]*p[5];
                b[j]=a[i][j];
                is[sum][i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            b[j]=a[i][j];
        }
        for(int j=1;j<=5;j++)
        {
            for(int k=1;k<=9;k++)
            {
                b[j]=(b[j]+k)%10;
                b[j+1]=(b[j+1]+k)%10;
                int sum=b[1]*p[1]+b[2]*p[2]+b[3]*p[3]+b[4]*p[4]+b[5]*p[5];
                b[j]=a[i][j];
                b[j+1]=a[i][j+1];
                is[sum][i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int sum=a[i][1]*p[1]+a[i][2]*p[2]+a[i][3]*p[3]+a[i][4]*p[4]+a[i][5]*p[5];
        //cout<<sum<<endl;
        is[sum][i]=0;
    }
    for(int i=0;i<=99999;i++)
    {
        int f=1;
        for(int j=1;j<=n;j++)
        {
            if(is[i][j]==0) f=0;
        }
        if(f) ans++;
    }
    cout<<ans;
    return 0;
}
