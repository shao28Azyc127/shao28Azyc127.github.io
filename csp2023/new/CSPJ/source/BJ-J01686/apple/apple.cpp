#include<bits/stdc++.h>
using namespace std;
int ans,cnt;
int tran(int x){
    return x%3==0 ? x/3 : x/3+1;
}
void f(int n){
    if(n==0){
        return;
    }
    cnt++;
    if((n-1)%3==0 && !ans){
        ans = cnt;
    }
    //cout << n << endl;
    f(n-tran(n));
}
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    f(n);
    cout << cnt << " " << ans;
    return 0;
}
