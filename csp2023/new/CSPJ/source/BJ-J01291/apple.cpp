#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int ans1=0,ans2=0;
    bool f=0;
    while(n){
        //cout<<n%3<<'\n';
        if(n%3==1&&f==0){
            ans2=ans1+1;
            f=1;
        }
        n-=n/3+(n%3!=0);
        ans1++;
    }
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}