#include<bits/stdc++.h>
using namespace std;
//need long long!!!!!!!!!!!!!!!!!!!!!!!
const long long N=1e5+10;
long long n,d,v[N],a[N],ans,len,sum;
long long b[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(long long i=1;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        b[i]=b[i-1]+v[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long j=1;
    for(long long i=1;i<=n;i=j){
        for(j=i+1;j<=n;j++){
            if(a[j]<a[i]) break;
        }
        if(j==n+1) j=n;
        long long ll=max(b[j-1]-len,(long long)0);
        long long oil=ll/d;
        if(ll%d) oil++;
        ans+=(oil*a[i]);
        len+=(oil*d);
        if(len>=sum) break;
    }
    cout<<ans;
    return 0;
}
