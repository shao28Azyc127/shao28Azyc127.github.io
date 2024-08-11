#include<iostream>
#include<cstring>
using namespace std;

const int maxn=5e5+10;
int c,n,m,q,ai[maxn],bi[maxn],ab[maxn],bb[maxn];

void solve(){
    if(ai[1]<bi[1]){
        bool success=1;
        int p1=0;
        for(int p2=1;p2<=n;p2++){
            while(bi[p1+1]>ai[p2]&&p1!=m)p1++;
            while(bi[p1]<ai[p2]&&p1!=0)p1--;
            if(p1==0){
                success=0;
                break;
           }
        }
        p1++;
        for(;p1<=m;p1++)success&=bi[p1]>ai[n];
        success&=bi[m]>ai[n];
        cout<<success;
    }else{
        bool success=1;
        int p1=0;
        for(int p2=1;p2<=m;p2++){
            while(ai[p1+1]>bi[p2]&&p1!=n)p1++;
            while(ai[p1]<bi[p2]&&p1!=0)p1--;
            if(p1==0){
                success=0;
                break;
            }
        }
        p1++;
        for(;p1<=n;p1++)success&=ai[p1]>bi[m];
        success&=bi[m]<ai[n];
        cout<<success;
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)cin>>ai[i];
    for(int i=1;i<=m;i++)cin>>bi[i];
    memcpy(ab,ai,sizeof(ai));
    memcpy(bb,bi,sizeof(bi));
    solve();
    for(int i=1;i<=q;i++){
        int x,y,p,v; cin>>x>>y;
        for(int i=1;i<=x;i++)cin>>p>>v,ai[p]=v;
        for(int i=1;i<=y;i++)cin>>p>>v,bi[p]=v;
        solve();
        memcpy(ai,ab,sizeof(ab));
        memcpy(bi,bb,sizeof(bb));
    }
    cout<<endl;
}