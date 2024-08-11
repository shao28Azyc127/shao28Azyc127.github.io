#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int flag[11][11][11][11][11];
inline void f(int a,int b,int c,int d,int e)
{
    for(int i=0;i<=9;++i)
    {
        if(i==a)
        {
            continue;
        }
        ++flag[i][b][c][d][e];
        //f(i,b,c,d,e);
    }
    for(int i=0;i<=9;++i)
    {
        if(i==b)
        {
            continue;
        }
        ++flag[a][i][c][d][e];
        //f(a,i,c,d,e);
    }
    for(int i=0;i<=9;++i)
    {
        if(i==c)
        {
            continue;
        }
        ++flag[a][b][i][d][e];
        //f(i,b,c,d,e);
    }
    for(int i=0;i<=9;++i)
    {
        if(i==d)
        {
            continue;
        }
        ++flag[a][b][c][i][e];
        //f(i,b,c,d,e);
    }
    for(int i=0;i<=9;++i)
    {
        if(i==e)
        {
            continue;
        }
        ++flag[a][b][c][d][i];
        //f(i,b,c,d,e);
    }
    return;
}
inline void ff(int a,int b,int c,int d,int e)
{
    for(int i=1;i<=9;++i)
    {
        ++flag[(a+i)%10][(b+i)%10][c][d][e];
    }
    for(int i=1;i<=9;++i)
    {
        ++flag[a][(b+i)%10][(c+i)%10][d][e];
    }
    for(int i=1;i<=9;++i)
    {
        ++flag[a][b][(c+i)%10][(d+i)%10][e];
    }
    for(int i=1;i<=9;++i)
    {
        ++flag[a][b][c][(d+i)%10][(e+i)%10];
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n,a,b,c,d,e;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b>>c>>d>>e;
        f(a,b,c,d,e);
        ff(a,b,c,d,e);
    }
    for(int i=0;i<=9;++i)
    {
        for(int j=0;j<=9;++j)
        {
            for(int k=0;k<=9;++k)
            {
                for(int l=0;l<=9;++l)
                {
                    for(int m=0;m<=9;++m)
                    {
                        if(flag[i][j][k][l][m]==n)
                        {
                            ++cnt;
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
