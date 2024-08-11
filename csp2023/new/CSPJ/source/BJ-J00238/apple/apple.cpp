#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,cnt;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0){
        ans++;
        if((n-1)%3==0&&cnt==0) cnt=ans;
        if((n+1)%3==0) n-=(n+1)/3;
        else if((n+2)%3==0) n-=(n+2)/3;
        else n-=n/3;
    }cout<<ans<<" "<<cnt<<endl;
    return 0;
}