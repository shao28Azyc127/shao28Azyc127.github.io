#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,d;
int a[maxn],v[maxn];
int sum[maxn];
int val=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    sum[0]=0;
    int j;
    int cnt=0;
    int x;
    for(int i=1;i<=n-1;i++) cin>>v[i],sum[i]=sum[i-1]+v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i=j){
        for(j=i;j<=n;j++){
            if(a[j]<a[i]){
                if(v[i]%d==0) val+=(sum[j-1]-sum[i-1]-cnt)/d*a[i],x=(sum[j-1]-sum[i-1]-cnt)/d;
                else val+=((sum[j-1]-sum[i-1])/d-cnt+1)*a[i],x=(sum[j-1]-sum[i-1]-cnt)/d+1;
                cnt=x*d-(sum[j-1]-sum[i-1]);
            }
        }
    }
    cout<<val;
    return 0;
}
