#include<bits/stdc++.h>
using namespace std;
int n,ans,res;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        if(res==0&&n%3==1){
            res=ans+1;
        }
        if(n%3==0){
            n-=n/3;
        }else{
            n-=n/3;
            n-=1;
        }
        ++ans;
    }
    cout<<ans<<" "<<res;
    return 0;
}
