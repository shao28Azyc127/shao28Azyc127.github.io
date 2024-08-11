#include<iostream>
#include<cstdio>
using namespace std;
int N,ans,a[9][6],b[6],mrk[6];
int cal(int x,int y)
{
    if(y-x<0) return y-x+10;
    return y-x;
}
void dfs(int t)
{
    if(t==6)
    {
        for(int i=1;i<=N;i++)
        {
            int cnt=0;
            for(int j=1;j<=5;j++)
                if(a[i][j]!=b[j])
                    mrk[++cnt]=j;
            if(cnt!=1&&cnt!=2) return;
            if(cnt==2)
            {
                if(mrk[2]-mrk[1]!=1) return;
                int x=mrk[1],y=mrk[2];
                if(cal(a[i][x],b[x])!=cal(a[i][y],b[y])) return;
            }
        }
        ans++; return;
    }
    for(b[t]=0;b[t]<=9;b[t]++) dfs(t+1);
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=5;j++)
            scanf("%d",&a[i][j]);
    dfs(1);
    printf("%d",ans);
    return 0;
}