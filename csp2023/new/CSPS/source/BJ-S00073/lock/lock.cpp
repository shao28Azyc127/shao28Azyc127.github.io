#include<iostream>
using namespace std;
int a[10][10];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=5;j++)
        {
            cin>>a[i][j];
        }
    }
    if(n==1)
    {
        cout<<81;
    }
    else
    {
        int ans=0;
        for(int i=1;i<=5;i++)
        {
            for(int j=0;j<=9;j++)
            {
                if(a[1][i]==j)continue;
                int flag=0;
                for(int k=2;k<=n;k++)
                {
                    int cnt1=0;
                    for(int q=1;q<=5;q++)
                    {
                        if(q==i)
                        {
                            if(j!=a[k][q])cnt1++;
                        }
                        else if(a[1][q]!=a[k][q])cnt1++;
                    }
                    if(cnt1==1)
                    {
                        flag=1;
                    }
                    int cnt2=0;
                    int shang=0;
                    for(int q=1;q<=6;q++)
                    {
                        if(q==i)
                        {
                            if((j-a[k][q])!=shang)
                            {
                                cnt2++;
                                shang=j-a[k][q];
                            }
                        }
                        else if(a[1][q]-a[k][q]!=shang)
                        {
                            cnt2++;
                            shang=a[1][q]-a[k][q];
                        }
                    }
                    if(cnt2==2)
                    {
                        flag=1;
                    }
                    if(flag==0)break;
                }
                if(flag==1)
                {
                    ans++;
                }

            }
        }
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=9;j++)
            {
                int x=a[1][i]+j;
                int y=a[1][i+1]+j;
                if(x>=10)x-=10;
                if(y>=10)y-=10;
                int flag=0;
                for(int k=2;k<=n;k++)
                {
                    int cnt1=0;
                    for(int q=1;q<=5;q++)
                    {
                        if(q==i)
                        {
                            if(x!=a[k][q])cnt1++;
                        }
                        else if(q==i+1)
                        {
                            if(y!=a[k][q])cnt1++;
                        }
                        else if(a[1][q]!=a[k][q])cnt1++;
                    }
                    if(cnt1==1)
                    {
                        flag=1;
                    }
                    int cnt2=0;
                    int cnt3=0;
                    int shang=0;
                    for(int q=1;q<=6;q++)
                    {
                        if(q==i)
                        {
                            if(x-a[k][q]!=shang)
                            {
                                cnt2++;
                                shang=x-a[k][q];
                            }

                            if(x-a[k][q]!=0)
                            {
                                cnt3++;
                            }
                        }
                        else if(q==i+1)
                        {
                            if((y-a[k][q])!=shang)
                            {
                                cnt2++;
                                shang=y-a[k][q];
                            }
                            if((y-a[k][q])!=0)
                            {
                                cnt3++;
                            }
                        }
                        else
                        {   if(a[1][q]-a[k][q]!=shang)
                            {
                                cnt2++;
                                shang=a[1][q]-a[k][q];
                            }
                            if(a[1][q]-a[k][q]!=0)
                            {
                                cnt3++;
                            }
                        }
                    }
                    if(cnt2==2&&cnt3==2)
                    {
                        flag=1;
                    }
                    if(flag==0)break;
                }
                if(flag==1)
                {
                    ans++;
                }
            }
        }
        cout<<ans;
    }
}
