#include<bits/stdc++.h>
using namespace std;
long long  n,cnt,cnt2,ans1,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    cnt=n;
    cnt2=n;
    while(cnt>0){
        if(cnt%3>=1) cnt-=(cnt/3+1);
        else cnt-=(cnt/3);
        ans1++;
    }
    cout<<ans1<<" ";
    if(n%3==1) {
        cout<<1;
        return 0;
    }
    while(cnt2>0){
        if(cnt2%3==1){
                ans2++;
                cout<<ans2;
                return 0;
        }
        else{
            if(cnt2%3>1){
                cnt2-=(cnt2/3+1);
                ans2++;
            }else{
                cnt2-=(cnt2/3);
                ans2++;
            }
        }
    }
    cout<<ans2;
    return 0;
}

