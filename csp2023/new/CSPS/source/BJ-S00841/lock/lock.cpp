#include <bits/stdc++.h>
using namespace std;
int n,sum=0;
int a[10],b[10],c[10],d[10],e[10];
int m[6][10][10],q[6][10][10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i];
    }
    if (n==1)
    {
        cout<<"81";
        return 0;
    }
    int s=1;
    for (int i=1;i<=5;i++)
    {
        if (i==1)
        {
            s=1;
            for (int j=1;j<=9;j++)
            {
                m[i][j][1]=((a[1]+s)%10)*10000+b[1]*1000+c[1]*100+d[1]*10+e[1];
                s++;
            }
        }
        if (i==2)
        {
            s=1;
            for (int j=1;j<=9;j++)
            {
                m[i][j][1]=a[1]*10000+((b[1]+s)%10)*1000+c[1]*100+d[1]*10+e[1];
                s++;
            }
        }
        if (i==3)
        {
            s=1;
            for (int j=1;j<=9;j++)
            {
                m[i][j][1]=a[1]*10000+b[1]*1000+((c[1]+s)%10)*100+d[1]*10+e[1];
                s++;
            }
        }
        if (i==4)
        {
            s=1;
            for (int j=1;j<=9;j++)
            {
                m[i][j][1]=a[1]*10000+b[1]*1000+c[1]*100+((d[1]+s)%10)*10+e[1];
                s++;
            }
        }
        if (i==5)
        {
            s=1;
            for (int j=1;j<=9;j++)
            {
                m[i][j][1]=a[1]*10000+b[1]*1000+c[1]*100+d[1]*10+((e[1]+s)%10);
                s++;
            }
        }
    }
    int p=1;
    for (int i=2;i<=n;i++)
    {
        for (int k=1;k<=5;k++)
        {
            if (k==1)
            {
                p=1;
                for (int j=1;j<=9;j++)
                {
                    for (int o=1;o<=5;o++)
                    {
                        for (int x=1;x<=9;x++)
                        {
                            if (m[o][x][1]==((a[i]+p)%10)*10000+b[i]*1000+c[i]*100+d[i]*10+e[i])
                            {
                                q[o][x][i]++;
                            }
                        }
                    }
                    p++;
                }
            }
            if (k==2)
            {
                p=1;
                for (int j=1;j<=9;j++)
                {
                    for (int o=1;o<=5;o++)
                    {
                        for (int x=1;x<=9;x++)
                        {
                            if (m[o][x][1]==a[i]*10000+((b[i]+p)%10)*1000+c[i]*100+d[i]*10+e[i])
                            {
                                q[o][x][i]++;
                            }
                        }
                    }
                    p++;
                }
            }
            if (k==3)
            {
                p=1;
                for (int j=1;j<=9;j++)
                {
                    for (int o=1;o<=5;o++)
                    {
                        for (int x=1;x<=9;x++)
                        {
                            if (m[o][x][1]==a[i]*10000+b[i]*1000+((c[i]+p)%10)*100+d[i]*10+e[i])
                            {
                                q[o][x][i]++;
                            }
                        }
                    }
                    p++;
                }
            }
            if (k==4)
            {
                p=1;
                for (int j=1;j<=9;j++)
                {
                    for (int o=1;o<=5;o++)
                    {
                        for (int x=1;x<=9;x++)
                        {
                            if (m[o][x][1]==a[i]*10000+b[i]*1000+c[i]*100+((d[i]+p)%10)*10+e[i])
                            {
                                q[o][x][i]++;
                            }
                        }
                    }
                    p++;
                }
            }
            if (k==5)
            {
                p=1;
                for (int j=1;j<=9;j++)
                {
                    for (int o=1;o<=5;o++)
                    {
                        for (int x=1;x<=9;x++)
                        {
                            if (m[o][x][1]==a[i]*10000+b[i]*1000+c[i]*100+d[i]*10+((e[i]+p)%10))
                            {
                                q[o][x][i]++;
                            }
                        }
                    }
                    p++;
                }
            }
        }
    }
    int z=0;
    for (int o=1;o<=5;o++)
    {
        for (int x=1;x<=9;x++)
        {
            z=0;
            for (int i=2;i<=n;i++)
            {
                if (q[o][x][i]>=1)
                {
                    z++;
                }
            }
            if (z==n-1)
            {
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
