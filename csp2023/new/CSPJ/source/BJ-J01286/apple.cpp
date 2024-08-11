#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    ll sum=n;
    ll cnt=0;
    ll ans=0;
    for(;;){
        if(sum%3==1&&ans==0){
            ans=cnt+1;
        }
        sum-=ceil(sum/3.0);
        cnt++;

//        cout<<1;
        if(sum<=3){
            cnt+=sum;
            if(ans==0){
                ans=cnt;
            }
            break;
        }
//        cout<<cnt<<" ";
    }
    cout<<cnt<<" "<<ans;
    return 0;
}
