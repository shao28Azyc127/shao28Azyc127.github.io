#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=0,f=1,ans;cin>>n;
    while(n){
        if(n%3==1&&f) f=0,ans=cnt+1;
        n=n-(n%3?n/3+1:n/3);cnt++;
    }
    cout<<cnt<<' '<<ans;
    return 0;
}