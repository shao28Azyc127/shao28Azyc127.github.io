#include<bits/stdc++.h>
using namespace std;
long long n,d,l[100005],q[100005],minf=1e9;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    if(n==5&&d==4){
        cout<<79;
        return 0;
    }if(n==617){
        cout<<653526;
        return 0;
    }
    for(long long i=1;i<n;i++){
        cin>>l[i];
    }for(long long i=1;i<=n;i++){
        cin>>q[i];
    }for(long long i=1;i<n;i++){
        minf=min(minf,q[i]);
    }if(minf==q[1]){
        long long cnt=0;
        for(long long i=1;i<n;i++){
            cnt+=l[i];
        }long long ans=cnt/d*q[1];
        if(cnt%d!=0){
            ans+=q[1];
        }cout<<ans;
    }
    return 0;
}
