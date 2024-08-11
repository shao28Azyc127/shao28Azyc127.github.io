#include <bits/stdc++.h>
using namespace std;
long long n,m,k,flag=LONG_MAX,maxa=LONG_MIN;
struct road
{
    long long v;
    long long t;
};
vector<road> a[1111111];

void dfs(long long p,long long ti)
{
    if(p==n)
    {
        if(ti%k==0)
        {
            flag=min(flag,ti);
        }
        return ;
    }
    for(long long i=0; i<a[p].size(); i++)
    {
        if(ti>=a[p][i].t)
        {
            dfs(a[p][i].v,ti+1);
            if(flag<ti)return ;
        }

    }
    return ;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    //dfs(1,499918);
    for(long long i=0; i<m; i++)
    {
        long long u,v,ggg;
        cin>>u>>v>>ggg;
        maxa=max(maxa,ggg);
        a[u].push_back({v,ggg});
    }
    long long l=0,r=maxa/k+1,ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        //cout<<"try"<<mid<<" "<<mid*k<<endl;
        flag=LONG_MAX;
        dfs(1,mid*k);
        //cout<<"111"<<endl;
        if(flag==LONG_MAX)
        {
            //cout<<"up\n";
            l=mid+1;
        }
        else
        {
            //cout<<"down\n";
            ans=flag;
            r=mid-1;
        }
        flag=LONG_MAX;
    }
    cout<<ans;
    return 0;
}

