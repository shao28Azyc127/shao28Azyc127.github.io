#include<bits/stdc++.h>
using namespace std;
long long n,ans,cnt,ans1,b;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    b=n;
    while(n>3){
            ans++;
        cnt=(n-1)%3;
        n=(n-1)/3*2;
        n=n+cnt;
    }
    cout<<n+ans<<" ";
    n=b;ans=1;
    while(n%3!=1){
            ans++;
        cnt=(n-1)%3;
        n=(n-1)/3*2;
        n=n+cnt;
    }
    cout<<ans;
    return 0;
    }
