#include <bits/stdc++.h>
using namespace std;
int n,a[10][10],b[85][10],sum;
bool ch(int xa,int ya,int xb,int yb)
{
    if((10+xb-xa)%10==(yb+10-ya)%10)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    //cout<<1;
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<=83;i++)
    {
        for(int j=1;j<=5;j++)
        {
            b[i][j]=a[1][j];
        }
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cnt++;
            b[cnt][i]=(a[1][i]+j)%10;
            if(i==5)
            {
                continue;
            }
            cnt++;
            b[cnt][i]=(a[1][i]+j)%10;
            b[cnt][i+1]=(a[1][i+1]+j)%10;
        }
    }
    if(n==1)
    {
        cout<<cnt;
        return 0;
    }
    for(int i=1;i<=cnt;i++)
    {
        bool flag=0;
        for(int j=2;j<=n;j++)
        {
            int r=0,p[6];
            for(int k=1;k<=5;k++)
            {
                p[k]=0;
            }
            for(int k=1;k<=5;k++)
            {
                if(a[j][k]!=b[i][k])
                {
                    r++;
                    p[r]=k;
                }
            }
            if(r==0||r>=3||(r==2&&p[1]!=p[2]-1))
            {
                flag=1;
                break;
            }
            if(r==2&&ch(a[j][p[1]],a[j][p[2]],b[i][p[1]],b[i][p[2]])==1)
            {
                flag=1;
                break;
            }
            //cout<<ch(a[j][p[1]],a[j][p[2]],b[i][p[1]],b[i][p[2]]);
            //cout<<b[i][1]<<b[i][2]<<b[i][3]<<b[i][4]<<b[i][5];
        }
        if(flag==0)
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}