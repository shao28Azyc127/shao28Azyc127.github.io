#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ll n;
    cin>>n;
    ll t=n;
    ll cnt=0,ans=0;
    while(t){
        cnt++;
        ll x=t/3+(t%3?1:0);
        if(t%3==1&&!ans){
            ans=cnt;
        }
        //cout<<x<<endl;
        t-=x;
    }
    cout<<cnt<<" "<<ans<<endl;
    return 0;
}
