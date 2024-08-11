#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int ans1=0,ans2;
    if(n%3==1) {
        ans2=1;
    }
    bool flag=false;
    while(n!=0) {
        ans1++;
        if(n%3==1&&flag==false) {
            ans2=ans1;
            flag=true;
        }
        if(n%3==0) {
            n-=n/3;
        }
        else {
            n-=n/3+1;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
