#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,ans;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(cnt=1;n;cnt++){
        switch(n%3){
        case 0:
            n-=n/3;
            break;
        case 1:
            if(ans==0){
                ans=cnt;
            }
            n-=(n+2)/3;
            break;
        case 2:
            n-=(n+1)/3;
            break;
        }
    }
    cout<<cnt-1<<" "<<ans;
}
