#include <bits/stdc++.h>
using namespace std;
long long n,d,ans,cnt,m;
long long a[10005],v[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    a[0]=2147483647;
    for(int i=1;i<n;i++)
        scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<a[m])m=i;
    }
    for(int i=1;i<=n;){
        if(i==m&&m!=n){
            for(int k=i;k<n;k++){
                    cnt+=v[k];
                }
                if(cnt%d==0)ans+=cnt/d*a[i];
                else ans+=(cnt/d+1)*a[i];
            cout<<ans<<endl;
            return 0;
        }
        for(int j=i;j<=n;j++){
            if(a[j]<a[i]){
                for(int k=i;k<j;k++){
                    cnt+=v[k];
                }
                if(cnt%d==0)ans+=cnt/d*a[i];
                else ans+=(cnt/d+1)*a[i];
                cnt=(-1)*((cnt/d+1)*d-cnt);
                i=j;
                if(j==n){
                    cout<<ans;
                    return 0;
                }
                break;
            }
        }
    }
    return 0;
}