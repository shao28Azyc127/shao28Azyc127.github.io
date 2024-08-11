include<iostream>
using namespace std;
int n,m,k,maxt,small=-1;
struct node
{
    bool flag=false;
    int time;
}g[1005][1005];
void dfs(int step,int t)
{
    if(step==n)
    {
        if(t%k==0)small=min(small,t);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=step)
        {
            if(g[i][step].flag==true&&g[i][step].time>=t)dfs(i,t+1);
        }
    }
    return ;
}
int main()
{
    freopen("bus,in","r",stdin);
    freopen("bus,out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y].flag=true;
        g[x][y].time=z;
        g[y][x].flag=true;
        g[y][x].time=z;
        maxt=max(maxt,z);
    }
    for(int i=1;i<=maxt/k;i++)
    {
        int f=i*k;//jinrudeshijian
        dfs(1,f);
    }
    cout<<small<<endl;
    return 0;
}
