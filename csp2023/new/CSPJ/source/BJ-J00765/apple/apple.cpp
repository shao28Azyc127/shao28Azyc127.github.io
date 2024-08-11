#include <bits/stdc++.h>
using namespace std;
long long n,ans,ans2,flag=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        ++ans;
        if(n%3==1&&flag) ans2=ans,flag=0;
        if(n%3==1||n%3==2) n-=(n/3+1);
        else n-=(n/3);
    }
    cout<<ans<<" "<<ans2;
    return 0;
}
