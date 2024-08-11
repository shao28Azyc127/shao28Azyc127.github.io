#include<bits/stdc++.h>
using namespace std;
const int N=50,M=1e5+10;
int mod=3;
struct nod
{
    int i,j,op,val;
}deal[N];
int sta[N],val[N],fin[N];
int d[M];
int main()
{
    ios::sync_with_stdio(0);
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        memset(deal,0,sizeof(deal));
        memset(d,0,sizeof(d));
        int ans=1e9;
        int n,m;
        cin>>n>>m;
        if(n>10)
        {
            ans=0;
            for(int K=1;K<=m;K++)
            {
                char op;int i;
                cin>>op>>i;
                if(op=='T')  d[i]=1;
                else if(op=='F')  d[i]=0;
                else  d[i]=2;
            }
            for(int i=1;i<=n;i++)
            {
                if(d[i]==2)  ans++;
            }
            cout<<ans<<'\n';
        }
        else
        {

            for(int K=1;K<=m;K++)
            {
                char op;
                int i,j;
                cin>>op;
                if(op=='+')  cin>>i>>j,deal[K].op=1,deal[K].i=i,deal[K].j=j;
                else if(op=='-')  cin>>i>>j,deal[K].op=2,deal[K].i=i,deal[K].j=j;
                else if(op=='T')  cin>>i,deal[K].op=3,deal[K].i=i,deal[K].val=1;
                else if(op=='F')  cin>>i,deal[K].op=3,deal[K].i=i,deal[K].val=0;
                else  cin>>i,deal[K].op=3,deal[K].i=i,deal[K].val=2;
            }
            int maxn=pow(3,n)-1;
            for(int S=0;S<=maxn;S++)
            {
                int x=S,cnt=0,flag=1,tot=0;
                memset(sta,0,sizeof(sta));
                memset(fin,0,sizeof(fin));
                for(int k=1;k<=n;k++)
                {
                    cnt++;
                    if(x%mod==2)  tot++;
                    sta[cnt]=x%mod;
                    x/=mod;
                }
                //cout<<" tot "<<tot<<" "<<S<<endl;
                //for(int i=1;i<=cnt;i++)  cout<<sta[i]<<" ";
                //cout<<endl;
                for(int i=1;i<=n;i++)  fin[i]=sta[i];
                for(int i=1;i<=m;i++)
                {
                    int x=deal[i].i,y=deal[i].j,val=deal[i].val;
                    if(deal[i].op==3)
                    {
                        fin[x]=val;
                    }
                    else if(deal[i].op==2)
                    {
                        if(fin[y]==1)  fin[x]=0;
                        else if(fin[y]==0)  fin[x]=1;
                        else if(fin[y]==2)  fin[x]=2;
                    }
                    else
                    {
                        fin[x]=fin[y];
                    }
                }
                flag=1;
                for(int i=1;i<=n;i++)  if(sta[i]!=fin[i])  flag=0;
                if(flag==1)  ans=min(ans,tot);
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}