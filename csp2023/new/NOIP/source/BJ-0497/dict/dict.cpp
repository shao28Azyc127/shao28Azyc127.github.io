#include <bits/stdc++.h>
using namespace std;
int mark[3010][30],n,m;
char c[3010];
struct node
{
    int mi,ma;
}a[3010];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[j];
            mark[i][c[j]-'a']++;
        }
        for(int j=0;j<26;j++)
            if(mark[i][j])
            {
                a[i].mi=j;
                break;
            }
        for(int j=25;j>=0;j--)
            if(mark[i][j])
            {
                a[i].ma=j;
                break;
            }
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=n;j++)
        {
            if(j==i)
                continue;
            if(a[j].ma<=a[i].mi)
            {
                flag=0;
                break;
            }
        }
        cout<<flag;
    }
    return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/