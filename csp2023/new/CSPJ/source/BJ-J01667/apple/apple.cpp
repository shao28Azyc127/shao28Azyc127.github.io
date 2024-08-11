#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int sum=n;
    int ans=0;
    while(sum!=0){
        if(sum%3==0){
            sum=sum-sum/3;
        }else {
            sum=sum-sum/3-1;
        }
        ans++;
    }
    cout<<ans<<" ";
    if(n%3==1){
        cout<<1;
        return 0;
    }
    sum=n;
    int h=1;
    ans=0;
    while(sum!=0){
        if(sum%3==1){
            cout<<ans+1;
            return 0;
        }
        if(sum%3==0){
            sum=sum-sum/3;
        }else {
            sum=sum-sum/3-1;
        }
        ans++;
    }
    return 0;
}
