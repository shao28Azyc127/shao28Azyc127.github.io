#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=0,ansd=0;
    cin>>n;
    while(n){
        if(n%3==1&&!ansd)ansd=ans+1;
        ans++;
        n-=ceil(n/3.00);
        //cout<<n<<' '<<ans<<' '<<ansd<<'\n';
    }
    cout<<ans<<' '<<ansd;
    return 0;
}
