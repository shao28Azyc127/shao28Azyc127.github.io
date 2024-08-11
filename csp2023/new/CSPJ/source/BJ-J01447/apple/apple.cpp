#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
using ll=long long;
ll n;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    ll ans=1;
    ll k=n;
    ll h=-1;
    bool flag=1;
    if((k-1)%3==0){
        flag=0;
        h=ans;
    }
    while(k>0){
        ans++;
        if((k-1)%3==0 && flag==1){
            flag=0;
            h=ans;
        }
        if(k<3){
            k--;
        }else{
            k=k-k/3-1;
        }
    }
    if(h==-1){
        h=ans;
    }
    cout<<ans<<" "<<h;
    return 0;
}
