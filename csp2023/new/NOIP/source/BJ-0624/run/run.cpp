#define ll long long
#include<iostream>
using namespace std;
const int M=500010;
ll C,T;
ll n,m,k,d;
ll s[M];
ll e[M];
ll l[M];
ll v[M];
ll xjb[M];
ll ans=0;
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >> C >> T;
    while(T--){
        cin >> n >> m >> k >> d;
        for(int i=1;i<=m;i++){
            cin >> e[i] >> l[i] >> v[i];
            s[i]=e[i]-l[i]+1;
            xjb[i]=v[i]-l[i]*d;
        }
        for(int i=1;i<=m;i++){
            if(xjb[i]>0&&l[i]<=k){
                ans+=xjb[i];
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
