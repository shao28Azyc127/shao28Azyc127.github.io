#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    long long n,m,t = 0,ans,flag = 1;
    cin >> n;
    while(n){
        t++;
        if((n - 1) % 3 == 0 && flag){
            ans = t;
            flag = 0;
        }
        m = (n - 1) / 3 + 1;
        n -= m;
    }
    cout << t << " " << ans;
    return 0;
}
