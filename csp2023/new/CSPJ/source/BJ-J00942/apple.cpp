#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,ans,i=0,f=1;
    cin>>n;
    while(n){
        i++;
        if(n%3==1 && f==1){
            ans=i;
            f=0;
        }
        n=n-(n+2)/3;
    }
    cout<<i<<" "<<ans;
    return 0;
}
