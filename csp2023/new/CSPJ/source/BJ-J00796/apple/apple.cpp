#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,ans_n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        ans++;
        if(n%3==1&&ans_n==0)ans_n=ans;
        else if(n%3==0)n-=n/3;
           else n-=((n/3)+1);
    }
    ans--;
    cout<<ans<<" "<<ans_n<<endl;
    return 0;
}