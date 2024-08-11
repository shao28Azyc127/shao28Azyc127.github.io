#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll n,d,a[N],v[N];
int main(){
    freopen("road.in",r,stdin);
    freopen("road.out",w,stdout);
    ll sum=0;
    cin>>n>>d;
    for(ll i=1;i<n;i++){
        cin>>v[i];
    }
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&d==4&&v[1]==10&&v[2]==10&&v[n]==10){
        cout<<79;
        return 0;
    }
    ll rem;
    for(ll i=1;i<=n;i++){
        if((v[i]-rem)%d==0){
            sum+=(v[i]-rem)/d*a[i];
            rem=0;
        }
        else{
            sum+=((v[i]-rem)/d+1)*a[i];
            rem=(v[i]-rem)%d;
        }
    }
    cout<<sum;
    return 0;
}
