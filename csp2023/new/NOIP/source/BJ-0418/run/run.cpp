#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int x[100010],y[100010],t[100010],a[10010],ans=0;
int n,m,d,k;
void dfs(int step,int sum)
{
    if(step>n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)cnt++;
            if(cnt>k)return;
            if(a[i]==0)cnt=0;
        }
        int num=0;
        for(int i=1;i<=m;i++)
        {
            bool f=1;
            for(int j=x[i]-y[i]+1;j<=x[i];j++)
            {
                if(a[i]==0)
                {
                    f=0;
                    break;
                }
            }
            if(f==1)num+=t[i];
        }
        ans=max(ans,num-sum*d);
        return;
    }
    a[step]=0;
    dfs(step+1,sum);
    a[step]=1;
    dfs(step+1,sum+1);
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--)
    {

        cin>>n>>m>>d>>k;
        for(int i=1;i<=m;i++)cin>>x[i]>>y[i]>>t[i];
        dfs(1,0);
        cout<<ans<<endl;
        ans=0;
    }

    return 0;
}