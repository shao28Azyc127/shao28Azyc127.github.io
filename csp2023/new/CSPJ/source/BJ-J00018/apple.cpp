#include<bits/stdc++.h>
using namespace std;
int n,ans1=0,ans2=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        if(n%3==1 && ans2==0){
            ans2=ans1+1;
        }
        if(n%3){
            n=n-n/3-1;
        }else n-=n/3;
        ans1++;
    }
    cout<<ans1<<" "<<ans2;

    return 0;
}
