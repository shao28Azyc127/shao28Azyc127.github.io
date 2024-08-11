#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,m,k,d,ans;
struct node{
    int l,r,v;
}c[100010];
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++){
            int x,y,val;
            cin>>x>>y>>val;
            c[i].l=x;
            c[i].r=x+y-1;
            c[i].v=val-y*d;
            if(c==18||c==17){
                if(c[i].v>0&&y<=k) ans+=c[i].v;
            }
        }if(c==18||c==17){
            cout<<ans<<'\n';
        }
    }
}