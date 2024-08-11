#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
ll f[1011][1011];
ll cf[1011];
struct o{
    ll x;
    ll y;
    ll v;
};
ll c,t;
ll n,m,k,d;
o chl[100011];
void inline sp(){

}
void inline ori(){
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++) f[i][j]=-1e16;
    }
}
bool inline cmp(o a,o b){
    return a.x<b.x;
}
void inline sol(){
    ori();
    cin >> n >> m >> k >> d;
    ll ans=0;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&chl[i].x,&chl[i].y,&chl[i].v);
    }
    sort(chl+1,chl+m+1,cmp);
    int lb=1;
    f[0][0]=0;
    for(ll i=0;i<n;i++){
        memset(cf,0,sizeof(cf));
        while(lb<=m&&chl[lb].x==i+1){
            cf[chl[lb].y]+=chl[lb].v;
            lb++;
        }
        /*
        cout << i << endl;
        for(int j=0;j<=n;j++) cout << cf[j] << ' ';
        cout << endl;
        */
        int tmpmin=min(i,k);
        ll delta=0;
        for(ll j=0;j<=tmpmin;j++){
            delta+=cf[j+1];
            f[i+1][0]=max(f[i+1][0],f[i][j]);
            if(j!=k) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+delta-d);
        }
    }
    for(ll i=0;i<=min(n,k);i++){
        ans=max(ans,f[n][i]);
    }
    cout << ans << endl;
    /*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    */
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
    cin >> c >> t;
    if(c==17||c==18){
        sp();
        return 0;
    }
    for(int i=1;i<=t;i++){
        sol();
    }
	return 0;
}
