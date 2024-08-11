#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,d,sum,v[100005],a[100005],x[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;a[0]=9e18;
    for(int i=1;i<n;i++)scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[ans]<a[i])x[ans]+=v[i];
        else{
            ll s=(x[ans]+d-1)/d*d-x[ans];
            while(s){
                if(v[i]>s){
                    v[i]-=s;
                    s=0;
                }else{
                    s-=v[i];v[i]=0;
                    i++;
                }
            }
            x[i]+=v[i];ans=i;
        }
    }
    for(int i=1;i<=n;i++)sum+=(x[i]+d-1)/d*a[i];
    cout<<sum<<endl;
    return 0;
}
