#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,k,d;
int sum,ans;
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    for(int o=1;o<=t;o++)
    {   cin>>n>>m>>k>>d;
        int tmp=0,da=0;
        ans=0;
        sum=0;
        for(int i=1;i<=m;i++)
        {
            int x,y,v;
            cin>>x>>y>>v;
            if(d*(y-sum)<v&&x<=k)
            {
              ans+=v-d*(y-sum);
              sum=y;
              da=x;
              tmp+=x-da;
              da=x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}