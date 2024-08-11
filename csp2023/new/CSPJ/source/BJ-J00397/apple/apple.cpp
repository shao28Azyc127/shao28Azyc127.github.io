#include <bits/stdc++.h>
using namespace std;
long long n,ans,ans2;
bool f;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    f=1;
    ans=ans2=0;
    int n1=n;
    while(n1>3){
        ans++;
        if(n1%3==1&&f){
            ans2=ans;
            f=0;
        }
        n1-=n1/3;
        if(n1%3!=0)
            n1--;
    }
    ans+=n1;
    if(ans2==0)
        ans2=ans;
    cout<<ans<<" "<<ans2;
    return 0;
}
