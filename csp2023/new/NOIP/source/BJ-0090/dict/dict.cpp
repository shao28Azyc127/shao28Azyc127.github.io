#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
char a[N][N];
bool cmp(char a,char b)
{
    return a<b;
}
bool cmp1(char a,char b)
{
    return a>b;
}
bool check(int i,int j)
{
    for(int k=1;k<=m;k++)
    {
        if(a[i][k]<a[j][k])return 1;
        else if(a[i][k]>a[j][k])return 0;
    }
    return 0;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(a[i]+1,a[i]+1+m,cmp1);
    }
    for(int i=1;i<=n;i++)
    {
        bool tg=0;
        reverse(a[i]+1,a[i]+1+m);
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(!check(i,j))
            {
                tg=1;
                break;
            }
        }
        reverse(a[i]+1,a[i]+1+m);
        if(tg)cout<<0;
        else cout<<1;
    }

}