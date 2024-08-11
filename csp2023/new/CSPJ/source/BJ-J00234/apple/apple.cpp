#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,i,ans=999999999;
    cin>>n;
    for(i=1;n!=0;i++){
        int k=n%3;
        if(k==1){
            ans=min(ans,i);
            n-=n/3+1;
        }
        if(k==0)
            n-=n/3;
        if(k==2){
            n-=n/3+1;
        }
    }
    cout<<i-1<<" "<<ans;
return 0;
}
