#include <iostream>
#include <cstdio>
using namespace std;
int n,a[10][7],b[7];

bool check(int p,int q)
{
    return a[2][p]+a[1][q]==a[2][p]+a[1][q];
}

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=5;j++)
            cin>>a[i][j];
    }
    if (n==1)
    {
        cout<<81<<endl;
        return 0;
    }
    else if (n==2)
    {
        int flag[6],cnt=0;
        for (int i=1;i<=5;i++)
        {
            flag[i]=a[1][i]-a[2][i];
            if (flag[i])
            {
                cnt++;
            }
        }
        if (cnt==0)
        {
            cout<<81<<endl;
        }
        else if (cnt==1)
        {
            cout<<10<<endl;
        }
        else if (cnt==2)
        {
            cout<<2<<endl;
        }
        else if (cnt==3)
        {
            int ans=0;
            for (int i=1;i<5;i++)
            {
                for (int j=i;j<=5;j++)
                {
                    if (check(i,j))
                    {
                        ans+=2;
                    }
                }
            }
        }
        else if (cnt==4)
        {
            int ans=0;
            for (int i=1;i<=2;i++)
            {
                for (int j=i+1;j<=3;j++)
                {
                    for (int k=j+1;k<=4;k++)
                    {
                         for (int l=k+1;l<=5;l++)
                         {
                             if (flag[i]&&flag[j]&&flag[k]&&flag[l])
                             {
                                int aa=i,bb=j,cc=k,dd=l;
                                 cout<<aa<<bb<<cc<<dd<<endl;
                                 if (check(aa,bb)&&check(cc,dd))
                                    ans++;
                                 if (check(aa,cc)&&check(bb,dd))
                                    ans++;
                                 if (check(aa,dd)&&check(bb,cc))
                                    ans++;
                             }
                         }
                    }
                }
            }
            cout<<ans<<endl;
        }
        else if (cnt==5)
        {
            cout<<0<<endl;
        }
        return 0;
    }
    return 0;
}
