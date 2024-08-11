#include <iostream>
#include <cstring>
bool poss[10][100000];
int a[10][10];
int tmp[10];
inline int calc()
{
    return tmp[5]*1+tmp[4]*10+tmp[3]*100+tmp[2]*1000+tmp[1]*10000;
}
void dfs(int r,int x,bool flag,int set)
{
    if(x==6)
    {
        if(!flag)
        {
            return;
        }
        int temp=calc();
        poss[r][temp]=true;
        return;
    }
    if(set!=0)
    {
        tmp[x]=(a[r][x]+set)%10;
        dfs(r,x+1,true,0);
        return;
    }
    if(flag)
    {
        tmp[x]=a[r][x];
        dfs(r,x+1,true,0);
        return;
    }
    for(int i=0;i<=9;i++)
    {
        if(a[r][x]!=i)
        {
            tmp[x]=i;
            dfs(r,x+1,true,0);
        }
    }
    if(x!=5)
    for(int i=1;i<=9;i++)
    {
        tmp[x]=(a[r][x]+i)%10;
        dfs(r,x+1,true,i);
    }
    tmp[x]=a[r][x];
    dfs(r,x+1,false,0);
}
int main()
{
    std::freopen("lock.in","r",stdin);
    std::freopen("lock.out","w",stdout);
    int n;
    std::cin>>n;
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=5;i++)
        {
            std::cin>>a[j][i];
        }
        dfs(j,1,false,0);
        std::memset(tmp,0,sizeof(tmp));
    }
    int ans=0;
    for(int j=0;j<100000;j++)
    {
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(!poss[i][j])
            {
                flag=true;
            }
        }
        if(!flag)
        {
            ans++;
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}