//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    int n; cin>>n;
    int tmp; tmp=n;
    int cnt; cnt=0;

    while(tmp){
        if(tmp%3==0){
            tmp-=tmp/3;
        }
        else{
            tmp-=tmp/3+1;
        }
        cnt++;
    }

    cout<<cnt;
    cout<<" ";

    tmp=n-1;

    int ans; ans=1;
    while(1){
        if(tmp%3==0){
            cout<<ans;
            return 0;
        }
        tmp-=(tmp/3)+1;
        ans++;
    }
    return 0;
}
