#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ans,ans1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int tmp=0;
    while(n>0){
        k=1+(n-1)/3;
        ans++;
        if((n-1)%3 == 0 && tmp==0){
            ans1=ans;
            tmp=1;
        }
        n-=k;
    }
    cout<<ans<<" "<<ans1;
    return 0;
}
