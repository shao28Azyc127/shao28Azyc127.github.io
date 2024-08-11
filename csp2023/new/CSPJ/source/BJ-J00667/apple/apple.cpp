#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 1000000007
using namespace std;

signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int i=0,ans=0;
    for(;n;i++){
        if((n-1)%3==0&&ans==0)ans=i+1;
        int take=(n-1)/3+1;
        n-=take;
    }
    cout<<i<<' '<<ans;
    return 0;
}