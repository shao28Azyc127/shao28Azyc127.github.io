#include<bits/stdc++.h>
using namespace std;
int n,ans=0,ans2;
bool flag=false;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        if(n%3==1&&!flag){
            ans2=ans+1;
            flag=true;
        }
        if(n%3==0) n-=(n/3);
        else n-=(n/3+1);
        ans++;
    }
    cout<<ans<<' '<<ans2<<'\n';
    return 0;
}