#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long v[maxn],a[maxn];
long long dmax,ans,k,n,d,tmp;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++){
        dmax=v[i];
        if(i == n-1){
            tmp=ceil(1.0*dmax / d);
            ans+=tmp*a[i];
            break;
        }
        for(int j=i+1;j<=n-1;j++){
            if(a[i] <= a[j]){
                dmax += v[j];
                if(j==n-1){
                    tmp=ceil(1.0*dmax / d);
                    v[j]-= tmp*d-dmax;
                    ans+=tmp*a[i];
                    cout<<ans;
                    return 0;
                }
            }
            else{
                tmp=ceil(1.0*dmax / d);
                v[j]-= tmp*d-dmax;
                ans+=tmp*a[i];
                i+=j-i-1;
                break;
            }
        }
    }
    cout<<ans;
}
