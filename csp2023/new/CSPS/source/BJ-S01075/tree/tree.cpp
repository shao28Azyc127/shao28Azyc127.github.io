#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005;
int dfn[N],day[N];
int n;
ll a[N],b[N],c[N],ans=1e11;
vector<int> g[N];
void update(){
    ll maxn=0;
    for(int i = 1;i<=n;i++){
        if(maxn-day[i]>=a[i]) continue;
        if(c[i]>=0){
            ll l = day[i],r=1e9,res=0;
            while(l<=r){
                int mid=l+r>>1;
                ll nn=(c[i]*mid+2*b[i]+day[i])*(mid-day[i]);
                if(nn>=a[i]*2){
                    res=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            maxn=max(maxn,res);
        }
        else{
            ll k=-b[i]/c[i];
            if(c[i]*k+b[i]<1) k--;
            if(day[i]>k){
                maxn=max(maxn,a[i]+day[i]);
            }
            else{
                if((c[i]*k+2*b[i]+c[i]*day[i+1])*k<=2*a[i]){
                    maxn=max(maxn,k+(2*a[i]-(c[i]*k+2*b[i]+c[i]*day[i+1])*k)/2);
                    continue;
                }
                ll l = day[i],r=k+1,res=0;
                while(l<=r){
                int mid=l+r>>1;
                ll nn=(c[i]*mid+2*b[i]+day[i])*(mid-day[i]);
                if(nn>=a[i]*2){
                    res=mid;
                    r=mid-1;
                }
                else l=mid+1;
                maxn=max(maxn,res);
            }
            }
        }
    }
    ans=min(ans,maxn);
}
void dfs(int u,int fa){
    int flag=1;
    for(int i = 0;i<g[u].size();i++){
        flag=0;
        int to=g[u][i];
        if(to==fa) continue;
        dfn[x]=to;
        day[to]=x;
        dfs(to,u);
    }
    if(flag) update();
}
int main()
{
    freopen("tree.in","r",stdin);
   freopen("tree.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i = 1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
    }
    dfn[1]=day[1]=1;
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
