#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans1,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    bool f=0;
    cin>>n;
    if((n-1)%3==0){
            ans2=1;
            f=1;
        }
    for(long long i=n;i>0;){
        if((i-1)%3==0&&f==0){
            ans2=ans1+1;
            f=1;
        }
        i-=(i-1)/3;
        i-=1;
        ans1++;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
