#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans1,ans2=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n!=0){
        ans1++;
        if(n%3==1 && ans2==-1) ans2=ans1;
        ll f=n/3;
        if((n%3)>0) f++;
        n-=f;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
