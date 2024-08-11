#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n,d,ans=0,sumv=0;
int v[maxn],a[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    int mina = a[1],much = 0;
    for(int i=1;i<n;i++){
        a[i] = min(mina,a[i]);
        mina = a[i];
    }
    for(int i=1;i<n;i++){
        if((v[i]-much)%d==0){
            ans += a[i]*((v[i]-much)/d);
            much = 0;
        }else{
            ans += a[i]*((v[i]-much)/d+1);
            much = ((v[i]-much)/d+1)*d+much-v[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
