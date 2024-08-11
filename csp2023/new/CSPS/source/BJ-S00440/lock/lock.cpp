#include<iostream>
using namespace std;
int a[10][10][10][10][10][10];
int l[100005];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    int i;
    int ans=0;
    cin>>n;
    for(int k=1;k<=n;k++)
    {
        int b,c,d,e,f;
        cin>>b>>c>>d>>e>>f;
        for(i=1;i<=9;i++)
        {
            if(b+i<0)
            {
                continue;
            }
            a[k][(b+i)%10][c][d][e][f]=1;
        }
        for(i=1;i<=9;i++)
        {
            if(c+i<0)
            {
                continue;
            }
            a[k][b][(c+i)%10][d][e][f]=1;
        }
        for(i=1;i<=9;i++)
        {
            if(d+i<0)
            {
                continue;
            }
            a[k][b][c][(d+i)%10][e][f]=1;
        }
        for(i=1;i<=9;i++)
        {
            if(e+i<0)
            {
                continue;
            }
            a[k][b][c][d][(e+i)%10][f]=1;
        }
        for(i=1;i<=9;i++)
        {
            if(f+i<0)
            {
                continue;
            }
            a[k][b][c][d][e][(f+i)%10]=1;
        }
        for(i=1;i<=9;i++)
        {
            a[k][(b+i)%10][(c+i)%10][d][e][f]=1;
        }
        for(i=1;i<=9;i++)
        {
            a[k][b][(c+i)%10][(d+i)%10][e][f]=1;
        }
        for(i=1;i<=9;i++)
        {
            a[k][b][c][(d+i)%10][(e+i)%10][f]=1;
        }
        for(i=1;i<=9;i++)
        {
            a[k][b][c][d][(e+i)%10][(f+i)%10]=1;
        }
        for(i=0;i<=9;i++)
        {
            for(int i1=0;i1<=9;i1++)
            {
                for(int i2=0;i2<=9;i2++)
                {
                    for(int i3=0;i3<=9;i3++)
                    {
                        for(int i4=0;i4<=9;i4++)
                        {
                            if(a[k][i][i1][i2][i3][i4]==1)
                            {
                                l[i*10000+i1*1000+i2*100+i3*10+i4]++;
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=1;i<=100001;i++)
    {
        if(l[i]==n)
        {
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
