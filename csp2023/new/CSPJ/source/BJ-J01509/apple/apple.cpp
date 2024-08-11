#include<bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int m=n;
    while(m){
        ans1++;
        m=m-(m+2)/3;
    }
    cout<<ans1<<" ";
    while(n){
        ans2++;
        if(n%3==1){
            cout<<ans2;
            return 0;
        }
        n=n-(n+2)/3;
    }
    return 0;
}
