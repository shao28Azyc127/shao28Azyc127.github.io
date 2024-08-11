#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <ctime>
#include <cstdlib>
#include <bitset>
using namespace std;
#define int long long
#define mod 998244353
#define mp make_pair
#define fi first
#define se second
#define pb push_back

int n,a[100005],b[100005],c[100005],lj[100005],mxx[100005],cnt[100005],u,v;
vector <int> e[100005];

void dfs(int x,int fat)
{
    for(auto i:e[x])
    {
        if(i==fat) continue; dfs(i,x); mxx[x]=min(mxx[x],mxx[i]-1);
        //cout<<"F "<<x<<" "<<i<<" "<<mxx[x]<<" "<<mxx[i]<<endl;
    }
}
int calc(int bh,int l,int r)
{
    if(c[bh]>=0||r<=lj[bh])
    {
        int aa=(b[bh]*2+c[bh]*(l+r)),bb=(r-l+1);
        return min((__int128)aa*bb/2,(__int128)2e18);
    }
    else if(l<=lj[bh])
    {
        return calc(bh,l,lj[bh])+(r-lj[bh]);
    }
    else
    {
        return r-l+1;
    }
}
bool ck(int x)
{
    //cout<<"G "<<x<<endl;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=x;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            //cout<<"P "<<i<<" "<<mid<<" "<<r<<" "<<calc(i,mid,x)<<endl;
            if(calc(i,mid,x)>=a[i]) l=mid+1; else r=mid-1;
        }
        mxx[i]=r;
        //cout<<i<<" "<<mxx[i]<<endl;
    }
    dfs(1,1);
    //for(int i=1;i<=n;i++) cout<<i<<" "<<mxx[i]<<endl;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++) if(mxx[i]<0) return 0;
    for(int i=1;i<=n;i++) if(mxx[i]<=n) cnt[mxx[i]]++;
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=0;i<=n;i++) if(cnt[i]>i) return 0;
    return 1;
}

signed main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin>>n; for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++) if(c[i]<0) lj[i]=(b[i]-1)/(-c[i]);
    for(int i=1;i<=n-1;i++) cin>>u>>v,e[u].pb(v),e[v].pb(u);
    int l=1,r=1000000000;
    while(l<=r)
    {
        int mid=(l+r)>>1; if(ck(mid)) r=mid-1; else l=mid+1;
    }
    cout<<l<<endl;
}
