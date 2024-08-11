#include<bits/stdc++.h>
using namespace std;
const int m=5,N=10;
int n;
int a[N][m+1];
int Solve()
{
    int cnt=0;
    int mark;
    for (int j=1;j<=m;++j)
    {
        if (a[1][j]!=a[2][j])
        {
            ++cnt;
            mark=j;
        }
    }
    if (cnt>2)
    {
        return 0;
    }
    if (cnt==2)
    {
        int mark[2],idx=0;
        for (int j=1;j<=m;++j)
        {
            if (a[1][j]!=a[2][j])
            {
                mark[idx]=j;
                ++idx;
            }
        }
        if ((int)abs(mark[0]-mark[1])==1)
        {
            if (((int)abs((a[1][mark[0]]-a[2][mark[0]]))&1)==0 && (int)abs((a[1][mark[0]]-a[2][mark[0]]))==(int)abs((a[1][mark[1]]-a[2][mark[1]])))
            {
                return 2;
            }
            return 0;
        }
        return 0;
    }
    if (cnt==1)
    {
        if (((int)abs((a[1][mark]-a[2][mark]))&1)==0)
        {
            if (mark==1 || mark==5)
            {
                return 10;
            }
            return 12;
        }
        return 8;
    }
    return 81;
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            cin>>a[i][j];
        }
    }
    if (n==1)
    {
        cout<<81;
        return 0;
    }
    if (n==2)
    {
        cout<<Solve();
        return 0;
    }
    cout<<0;
    return 0;
}
