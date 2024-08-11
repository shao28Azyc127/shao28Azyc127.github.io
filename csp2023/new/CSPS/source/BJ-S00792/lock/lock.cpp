#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[10][10],d[10][10];
int f[10],x[10];
int y[10],z[10];
int flag,num;
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
            d[i][j]=a[i][j]-a[i][j-1];
        }
    }
    for(int i=0;i<=99999;i++)
    {
        flag=i;
        for(int j=1;j<=5;j++)
        {
            f[j]=flag%10;
            flag/=10;
        }
        for(int j=1;j<=5;j++)
        {
            x[j]=f[6-j]-f[7-j];
        }
        flag=0;
        for(int j=1;j<=n;j++)
        {
            num=0;
            for(int k=1;k<=5;k++)
            {
                if(d[j][k]!=x[k])
                {
                    y[++num]=d[j][k]-x[k];
                    z[num]=k;
                }
            }
            if(num==1&&z[1]==5)
            {
                continue;
            }
            if(n==1&&!num)
            {
                continue;
            }
            if(num!=0&&num!=2)
            {
                flag=1;
                break;
            }
            if(num==2&&y[1]!=-y[2])
            {
                flag=1;
                break;
            }
            if(num==2&&z[2]-z[1]>3)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
