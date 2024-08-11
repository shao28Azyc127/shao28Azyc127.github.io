#include<bits/stdc++.h>
using namespace std;
int n,d,t=1,s,ans,a[100010],b[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];

    }
    for(int i=1;i<=n-1;i++){
        s+=a[i];
        if(b[i+1]<=b[t]){
            if(s%d==0){
                ans+=(s/d)*b[t];
                s=0;
            }else{
                ans+=(s/d+1)*b[t];
                s=0-(s/d+1)*d+s;
            }
            t=i+1;
        }
    }
    cout<<ans;
    return 0;
}
