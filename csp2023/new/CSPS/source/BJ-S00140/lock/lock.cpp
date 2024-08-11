#include<bits/stdc++.h>
using namespace std;
int n,a[110][110],oo;
int main()
{
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
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                for(int l=0;l<=9;l++)
                {
                    for(int m=0;m<=9;m++)
                    {
                        int u=0;
                        for(int s=1;s<=n;s++)
                        {
                            if(i==a[s][1] && j==a[s][2] && k==a[s][3] && l==a[s][4] && m==a[s][5])
                            {
                                u=1;
                                break;
                            }
                            int sum,num=0,h=0,q=0;
                            for(int x=1;x<=5;x++)
                            {
                                if(x==1) sum=i;
                                if(x==2) sum=j;
                                if(x==3) sum=k;
                                if(x==4) sum=l;
                                if(x==5) sum=m;
                                if(a[s][x]!=sum && num==0)
                                {
                                    num=1;
                                    h=x;
                                    q=sum-a[s][x];
                                    if(q<0)
                                    {
                                        q+=10;
                                    }
                                }
                                else if(a[s][x]!=sum && num==1)
                                {
                                    int bb=sum-a[s][x];
                                    if(bb<0) bb+=10;
                                    if(h==x-1 && q==bb)
                                    {
                                        u=0;
                                    }
                                    else
                                    {
                                        u=1;
                                        break;
                                    }
                                }
                            }
                            if(u==1) break;
                        }
                        if(u==0) oo++;
                  }
                }
            }
        }
    }
    cout<<oo;
    return 0;
}
