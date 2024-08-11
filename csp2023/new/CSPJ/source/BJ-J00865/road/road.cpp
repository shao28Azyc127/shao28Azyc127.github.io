#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,d,ans,p=LLONG_MAX;
double f;
int v[100010],a[100010];

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        p=min(p,a[i]);
        double res=1.0*v[i]-f*(1.0*d);
        if(res<=0){
            f-=((1.0*v[i])/(1.0*d));
            continue;
        }
        f=ceil(res/(1.0*d))-(res/(1.0*d));
        ans+=(ceil(res/(1.0*d))*p);
    }
    cout<<ans;

    return 0;
}
