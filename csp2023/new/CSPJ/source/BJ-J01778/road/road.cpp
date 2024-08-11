#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,d,v[N],a[N],sum,f;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]>=a[1]) f++;
    }
    if(f==n){
        if(sum%d==0){
            cout<<sum/d*a[1];
        }else{
            cout<<(sum/d+1)*a[1];
        }
    }else{
        int lef=0,sum=0;
        for(int i=1;i<n;i++){
            if(lef<v[i]){
                if((v[i]-lef)%d==0){
                    int t=lef;
                    lef=v[i];
                    sum+=a[i]*((v[i]-t)/d);
                }else{
                    int t=lef;
                    lef=((v[i]-lef)/d+1)*d;
                    sum+=a[i]*((lef-t)/d);
                }
            }
            lef-=v[i];
        }
        cout<<sum;
    }
    return 0;
}
