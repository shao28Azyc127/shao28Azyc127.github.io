#include <bits/stdc++.h>
using namespace std;

long long n,m,k,l,ans;
long long d[110][5];

void dfs(long long day,long long run,long long power)
{
    if(ans==0)
        ans=power;
    else
        ans=max(power,ans);
    if(day>n)
        return ;
    if(run==k)
    {
        dfs(day+1,0,power);
        return ;
    }
    int f=0;
    for(long long i=1;i<=m;i++)
    {
        if(d[i][1]==day)
        {
            if((run+1)>=d[i][2])
            {
                dfs(day+1,run+1,power-l+d[i][3]);
                f=1;
            }
        }
    }
    if(f==0)
        dfs(day+1,run+1,power-l);
    dfs(day+1,0,power);
    return ;
}

int main()
{
	freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==1 ||c==2)
    {
        while(t--)
        {
            cin>>n>>m>>k>>l;
            for(long long i=1;i<=m;i++)
            {
                    cin>>d[i][1]>>d[i][2]>>d[i][3];
            }
            ans=0;
            dfs(1,0,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}
