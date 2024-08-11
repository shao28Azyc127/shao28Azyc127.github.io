#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int sid,n,m,q,a[N],b[N],aa[N],bb[N];
int dp[2010][2010];
inline int getans(){
    if(sid<=7){
        int tg=0;
        if(a[1]>b[1]){
            swap(n,m),tg=1;
            for(int i=1;i<=max(n,m);i++) swap(a[i],b[i]);
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]>=b[j]){dp[i][j]=0;continue;}
                dp[i][j]=(dp[i-1][j]|dp[i][j-1]|dp[i-1][j-1]);
            }
        }
        return dp[n][m];
    }
    return 0;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>sid>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i],aa[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i],bb[i]=b[i];
    }
    if(sid<=7){
        cout<<getans();
        for(int i=1;i<=n;i++) a[i]=aa[i];
        for(int i=1;i<=m;i++) b[i]=bb[i];
        while(q--){
            int kx,ky; cin>>kx>>ky;
            while(kx--){
                int p,v; cin>>p>>v;
                a[p]=v;
            }
            while(ky--){
                int p,v; cin>>p>>v;
                b[p]=v;
            }
            cout<<getans();
            for(int i=1;i<=n;i++) a[i]=aa[i];
            for(int i=1;i<=m;i++) b[i]=bb[i];
        }
        return 0;
    }
    return 0;
}
