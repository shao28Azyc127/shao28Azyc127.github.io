#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn=1e5+10;
int n,d,u[maxn],a[maxn];
int mn[maxn];
long long sum[maxn],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>u[i],sum[i]=sum[i-1]+u[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    mn[1]=a[1];
    for(int i=2;i<=n;i++) mn[i]=min(mn[i-1],a[i]);
    long long now=0;
    for(int i=1;i<n;i++){
        //cout<<i<<' ';
        if(a[i]==mn[i]){
            int j=i;
            while(mn[j+1]==mn[i]&&j+1<n) j++;
            long long res=sum[j]-sum[i-1];
            ans+=1ll*(res-now+d-1)/d*a[i];
            if((res-now)%d==0) now=0;
            else now+=1ll*(res-now+d-1)/d*d-res;
            i=j;
        }
    }
    cout<<ans<<endl;
    return 0;
}
