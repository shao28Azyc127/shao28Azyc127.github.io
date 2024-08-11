#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,d;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n){
        cnt++;
        if(n%3==1&&!d)d=cnt;
        n-=ceil(1.0*n/3.0);
    }
    cout<<cnt<<" "<<d;
    return 0;
}
