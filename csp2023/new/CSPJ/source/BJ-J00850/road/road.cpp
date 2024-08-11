#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
#define int long long
int n,v[N],a[N],b[N],bz[N],sum[N],ans,d;
long double cnt;
signed main(){
    //freopen("road2.in","r",stdin);
    //freopen("road2.out","w",stdout);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
        sum[i]=sum[i-1]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int last=1;
    bz[1]=1;
    b[1]=1;
    for(int i=2;i<=n;i++){
        if(a[last]<a[i]){
            b[last]=i;
            bz[i]=last;
        }
        else{
            last=i;
            bz[i]=i;
            b[i]=i;
        }
    }
    for(int i=1;i<=n;i++){
        b[i]=b[bz[i]];
    }
    sum[n]=sum[n-1];
    for(int i=1;i<=n;i=b[i]+1){
        if(cnt*d<sum[b[i]]-sum[i-1]){
            int dc=sum[b[i]]-sum[i-1];
            double f=cnt*d;
            int x=ceil((dc-f)/d);
            double y=(dc-f)/d;
            cnt=cnt+x-y;
            ans=ans+x*a[i];
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}