#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,m,k,d;
int f[10005];
struct node{
    int l,r,val;
}hh[10005];
bool cmp(node a,node b){
    return a.r<b.r;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            int x,y,v;
            cin>>x>>y>>v;
            hh[i].r=x;
            hh[i].l=x-y+1;
            hh[i].val=v;
        }
        sort(hh+1,hh+m+1,cmp);
        memset(f,-0x3f,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=i;j>=1 && i-j+1<=k;j--){
                int val=(i-j+1)*(-d);
                for(int o=1;o<=m;o++){
                    if(hh[o].l>=j && hh[o].r<=i)val+=hh[o].val;
                }
                for(int o=1;o<j-1;o++){
                    f[i]=max(f[i],f[o]+val);
                }
                f[i]=max(f[i],val);
                //cout<<f[i]<<endl;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,f[i]);
        }
        cout<<ans<<"\n";
    }
}
