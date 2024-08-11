#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=0,ans1,flag=0;
    cin>>n;
    while(n){
        if(n%3==1&&flag==0){
            ans1=ans+1;
            flag=1;
        }
        n-=ceil(n/3.0);
        ans++;
    }
    cout<<ans<<" "<<ans1;
    return 0;
}