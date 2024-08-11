#include<bits/stdc++.h>
using namespace std;
const int N=50;
struct nod
{
    int day,val;
}rew[N];
int s[N],run[N];
int main()
{
    ios::sync_with_stdio(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,m,k,d,ans=0;
        memset(rew,0,sizeof(rew));
        cin>>n>>m>>k>>d;
        if(n>30)
        {
            cout<<0<<endl;
            continue;
        }
        int x,y,v;
        for(int i=1;i<=m;i++)
            cin>>x>>y>>v,rew[x].day=y,rew[x].val=v;
        int maxn=(1<<n)-1;
        for(int S=0;S<=maxn;S++)
        {
            memset(run,0,sizeof(run));
            memset(s,0,sizeof(s));
            int x=S,cnt=1;
            while(x)
            {
                if(x%2)  run[cnt]=1;
                x/=2,cnt++;
            }
            int flag=1,con=0,sum=0;
            //for(int i=1;i<=n;i++)  cout<<run[i]<<" ";
            //cout<<endl;
            for(int i=1;i<=cnt;i++)
            {
                if(run[i]==1)  con++,s[i]=con;
                if(run[i]==0)  con=0;
                if(con>k)  flag=0;
                //cout<<s[i]<<" ";
            }
            //cout<<endl;
            if(flag==0)  continue;
            for(int i=1;i<=n;i++)
            {
                if(s[i]>=rew[i].day)  sum+=rew[i].val;
                if(run[i])  sum-=d;
            }
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
it's already 12:50 now
i still don't konw any correct solvement of this task
i just wanna say
hope i can survive in the following days of this term 
wish my whk teachers will just forgive me.
i'm at senior 1 now why i'm so cai

bye noip 
*/
