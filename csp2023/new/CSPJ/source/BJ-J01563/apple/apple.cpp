#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum,ans=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        sum++;
        if(n%3==1&&ans==-1)ans=sum;
        n-=((n+2)/3);
    }
    cout<<sum<<' '<<ans<<'\n';
    return 0;
}
