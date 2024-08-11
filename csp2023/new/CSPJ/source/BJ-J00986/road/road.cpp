#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long n,d,ans=0;
    cin>>n>>d;
    long v[n],a[n];
    for(int i=0;i<n-1;i++)cin>>v[i];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            ans+=v[i]/d*a[i];
        }else{
            if(a[i-1]<=a[i]){
                ans+=(v[i]+v[i+1])/d*a[i-1];
                i++;
            }else{
                ans+=(v[i]+v[i+1])/d*a[i];
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}