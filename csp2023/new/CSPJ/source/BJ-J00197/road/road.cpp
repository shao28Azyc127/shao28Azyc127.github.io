#include <bits/stdc++.h>
using namespace std;
int n,m,d,cnt=0,ans=0,cntts=0,wz=1,you=0;
const int maxn=1e5+5;
int v[maxn],a[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n>1000){
            for(int i=1;i<=n;i++){
                cntts+=v[i];
            }
            for(int i=1;i<=n;i++){
                if(d*i>=cntts){
                    cout<<a[1]*i<<endl;
                    return 0;
                }
            }
    }
    while(wz!=n){
    for(int i=wz;i<=n-1;i+=0){
        if(a[i]>=a[i+1]){
            for(int j=1;j<=n;j++){
                if(j*d+you>=v[i]){
                    ans+=a[i]*j;
                    you=j*d+you-v[i];
                }
            }
        }else{
            cnt=v[i]+v[i+1];
            for(int j=i+2;j<=n;j++){
                if(a[i]>=a[j]){
                    for(int k=1;k<=n;k++){
                        if(k*d>=cnt){
                        ans+=a[i]*k;
                        wz=j;
                        you=j*d+you-v[i];
                        break;
                        }
                    }
                break;
                }
                cnt+=v[j];
            }
        }
    }
    }
    cout<<ans<<endl;
    return 0;
}