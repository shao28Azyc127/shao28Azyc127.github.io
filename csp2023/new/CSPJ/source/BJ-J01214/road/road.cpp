#include<bits/stdc++.h>
using namespace std;
#define int long long
int dd;
int v[100009];
int a[100009];
int ans;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[n]=-1;
    int t;
    t=1;
    while(1){
        if(t==n){
            cout<<ans<<endl;
            return 0;
        }
        int sum;
        sum=0;
        for(int i=t+1;i<=n;i++){
            sum+=v[i-1];
            if(a[i]<a[t]){
                sum-=dd;
                if(sum%d){
                    ans+=(sum/d+1)*a[t];
                    dd=(sum/d+1)*d-sum;
                }else{
                    ans+=sum/d*a[t];
                    dd=0;
                }
                t=i;
                break;
            }
        }
    }
    return 0;
}
