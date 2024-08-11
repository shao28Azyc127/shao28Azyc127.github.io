#include<bits/stdc++.h>
using namespace std;
int n;
int ans,cnt;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int ans=0,d;
    bool f=true;
    while(n){
        ans++;
        if(n%3==1 && f==true){
            d=ans;
            f=false;
        }
        if(n%3==0){
            n-=n/3;
        }else if(n%3==1){
            n-=(n+2)/3;
        }else
            n-=(n+1)/3;
    }
    cout<<ans<<" "<<d;
    return 0;
}