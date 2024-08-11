#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+10;
int n,m,k,d;
struct node
{
    int x,y,v;
}a[maxn];
int f[1010][1010];
int D[1010];
vector<node> vec[maxn];
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false);
    int T,C;
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].v;
        if(C<=9)
        {
            for(int i=1;i<=n;i++) vec[i].clear();

            for(int i=1;i<=m;i++) vec[a[i].x].push_back(a[i]);
            memset(f,-0x3f,sizeof(f));
            f[0][0]=0;
            for(int i=1;i<=n;i++)
            {
                int mx=-2e18;
                for(int j=0;j<=k;j++) mx=max(mx,f[i-1][j]);
                f[i][0]=mx;
                for(int j=1;j<=k;j++) f[i][j]=f[i-1][j-1]-d;
                for(int j=0;j<=k;j++) D[j]=0;
                for(int j=0;j<vec[i].size();j++)
                {
                    node t=vec[i][j];
                    D[t.y]+=t.v;
                }
                for(int j=1;j<=k;j++) D[j]+=D[j-1];
                for(int j=0;j<=k;j++) f[i][j]+=D[j];
            }
            int ans=-2e18;
            for(int i=0;i<=k;i++) ans=max(ans,f[n][i]);
            cout<<ans<<endl;
            continue;
        }
        if(C==17||C==18)
        {
            int ans=0;
            for(int i=1;i<=m;i++)
            {
                if(a[i].y*d<a[i].v) ans+=a[i].v-a[i].y*d;
            }
            cout<<ans<<endl;
            continue;
        }
    }
	return 0;
}
