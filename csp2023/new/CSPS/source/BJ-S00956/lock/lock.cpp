#include<bits/stdc++.h>
using namespace std;
int n,a[105][105],ans,b[105],st[15][15];
int check()
{
    int num=0,p1,p2;
    for(int i=1;i<=n;i++)
    {
        num=p1=p2=0;
        for(int j=1;j<=5;j++)
        {
            if(a[i][j]==b[j]) num++;
            else
            {
                if(p1==0) p1=j;
                else p2=j;
            }
        }
        if(num==5) return 0;
        if(num<3) return 0;
        if(num==3 && (p2-p1!=1 || st[b[p1]][a[i][p1]]!=st[b[p2]][a[i][p2]])) return 0;
    }
    return 1;
}
void dfs(int dep)
{
    if(dep==6)
    {
        ans+=check();
        return;
    }
    for(int i=0;i<=9;i++)
    {
        b[dep]=i;
        dfs(dep+1);
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int x;
    for(int i=0;i<=9;i++)
    {
        x=i;
        for(int j=0;j<=9;j++)
        {
            st[i][x]=j;
            x=(x+1)%10;
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++) cin>>a[i][j];
    dfs(1);
    cout<<ans<<'\n';
    return 0;
}
