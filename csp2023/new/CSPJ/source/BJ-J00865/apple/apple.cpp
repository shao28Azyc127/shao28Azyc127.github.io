#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a,cnt;

signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    while(n){
        cnt++;
        if(n>3&&a==0&&n%3==1){
            a=cnt;
        }
        if(n<=3){
            n--;
        }
        else if(n%3==0){
            n=n-n/3;
        }
        else{
            n=n-(n/3+1);
        }
    }
    if(a==0){
        a=cnt;
    }
    cout<<cnt<<" "<<a;

    return 0;
}
