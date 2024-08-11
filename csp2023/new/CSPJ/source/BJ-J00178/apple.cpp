#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int sum=n,ans=0;
    while(sum!=0){
        sum-=(sum+2)/3;
        ans++;
    }
    cout<<ans<<' '<<1;
    return 0;
}
