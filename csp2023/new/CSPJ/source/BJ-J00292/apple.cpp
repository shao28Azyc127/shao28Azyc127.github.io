#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,cnt;
bool flag=true;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0){
        ans++;
        if(n%3==1&&flag) {cnt=ans;flag=false;}
        int f=n/3;
        if(n%3!=0) f++;
        n-=f;
    }
    cout<<ans<<' '<<cnt;
    return 0;
}
