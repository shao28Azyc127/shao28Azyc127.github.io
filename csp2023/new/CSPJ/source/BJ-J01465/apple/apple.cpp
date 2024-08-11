#include<bits/stdc++.h>
using namespace std;
long long n,ans1=0,ans2=-1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        ans1++;
        if((n-1)%3==0&&ans2==-1)ans2=ans1;
        n-=(n-1)/3+1;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
