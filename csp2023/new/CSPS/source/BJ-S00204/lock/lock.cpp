#include<iostream>
using namespace std;
struct di
{
    int t[6];
};
int n,ans,vis[1000010][10];
void up(di &x,int li)
{
    if(x.t[li]==9)
        x.t[li]=0;
    else
        x.t[li]++;
}
void down(di &x,int li)
{
    if(x.t[li]==0)
        x.t[li]=9;
    else
        x.t[li]--;
}
int pow(int x)
{
    int res=1;
    for(int i=1;i<=x;i++)
        res*=10;
    return res;
}
int make(di a)
{
    int res=0;
    for(int i=1;i<=5;i++)
    {
        res=res*10+a.t[i];
    }
    //cout<<res<<endl;
    return res;
}
int update(di a,int rd)
{
    int tmp=make(a);
    if(vis[tmp][0]!=-1)
    {
        vis[tmp][rd]=1;
    }
}
int main()
{

    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int k=1;k<=n;k++)
    {
        di t;
        for(int i=1;i<=5;i++)
        {
            cin>>t.t[i];
        }
        //if(vis[make(t)]==1)ans--;
        vis[make(t)][0]=-1;
        //ans++;
        for(int j=1;j<=5;j++)
        {
            for(int m=1;m<=19;m++)
            {
                up(t,j);
                update(t,k);
            }
            for(int m=1;m<=19;m++)
            {
                down(t,j);
            }
        }
        for(int j=1;j<5;j++)
        {
            for(int m=1;m<=19;m++)
            {
                up(t,j);up(t,j+1);
                update(t,k);
            }
            for(int m=1;m<=19;m++)
            {
                down(t,j);down(t,j+1);
            }
        }
    }
    ans=0;
    int tp=0;
    for(int i=0;i<=99999;i++)
    {
        tp=0;
        for(int j=1;j<=n;j++)
        {
            if(vis[i][j])
                tp++;
        }
        if(tp==n)
            ans++;
    }
    cout<<ans;
    return 0;

}
