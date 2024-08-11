#include<iostream>
using namespace std;
const int maxn=15;
int a1[maxn][10],now[10],pos[maxn],cnt[10];
int ans=0,in;
bool check(int x,int y,int x1,int y1)
{
    if(x>x1)x1+=10;
    return (y+x1-x)%10==y1;
}
void dfs(int cur)
{
    if(cur>5)
    {
        bool flag=true;
        for(int v1=1;v1<=in&&pos;v1++)flag&=pos[v1]>0;
        if(flag)
        {
            //for(int v1=1;v1<cur;v1++)cout<<now[v1]<<' ';
            //for(int v1=1;v1<cur-1;v1++)if(now[v1]!=a1[1][v1]&&now[v1+1]!=a1[1][v1+1])cnt[v1]++;
            //cout<<endl;
            ans++;
        }
    }
    else for(int v1=0;v1<=9;v1++)
    {
        now[cur]=v1;
        bool flag=true;
        for(int v2=1;v2<=in;v2++)
        {
            if(v1==a1[v2][cur])continue;
            if(pos[v2]!=0&&pos[v2]!=cur-1)
            {
                flag=false;
                break;
            }
            if(!pos[v2])pos[v2]=cur;
            else if(!check(a1[v2][cur-1],a1[v2][cur],now[cur-1],now[cur]))
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            dfs(cur+1);
        }
        for(int v2=1;v2<=in;v2++)if(pos[v2]==cur)pos[v2]=0;
    }
}
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>in;
    for(int v1=1;v1<=in;v1++)for(int v2=1;v2<=5;v2++)scanf("%d",&a1[v1][v2]);
    dfs(1);
    //for(int v1=1;v1<=5;v1++)cout<<cnt[v1]<<endl;
    cout<<ans<<endl;
    return 0;
}
