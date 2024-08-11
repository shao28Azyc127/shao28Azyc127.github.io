#include <bits/stdc++.h>
using namespace std;
long long n,ans1,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    bool flat=false;
    cin>>n;
    if(n%3==1){
        ans2 = 1;flat=true;
    }
    while(n>0){
        ans1++;
        n=(n%3==0)?(n-n/3):(n-n/3-1);
        if(n%3==1&&flat == false){
            ans2=ans1+1;flat=true;
        }
    }
    
    cout<<ans1<<" "<<ans2;
    return 0;
}
