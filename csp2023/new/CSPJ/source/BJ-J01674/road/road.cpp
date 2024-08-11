#include<bits/stdc++.h>
using namespace std;
long long n,d,a[100000],c[100000];
long long l,ans,cmin;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i = 0;i < n-1;i++){
        cin>>a[i];
    }
    for(int i = 0;i < n;i++){
        cin>>c[i];
    }
    cmin = c[0];
    for(int i = 0;i < n-1;i++){
        cmin = min(c[i],cmin);
        if(l < a[i]){
            if((a[i]-l)%d == 0){
                ans += (a[i]-l)/d*cmin;
                l = a[i];
            }else{
                ans += ((a[i]-l)/d+1)*cmin;
                l += ((a[i]-l)/d+1)*d;
            }
        }
        l -= a[i];
    }
    cout<<ans;
    return 0;
}
