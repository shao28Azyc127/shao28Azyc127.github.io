#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int cnt=0,ans=0;
    while(n){
        cnt++;
        if(ans==0&&n%3==1) ans=cnt;
        int nxt=n/3;
        if(n%3!=0) nxt++;
        n-=nxt;
    }
    cout<<cnt<<' '<<ans;
}