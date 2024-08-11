#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,i = 0,ans = 0;
    cin >> n;
    while(n){
        i++;
        if(n % 3 == 1 && !ans){
            ans = i;
        }
        n -= (n + 2) / 3;
    }
    cout << i << " " << ans;
    return 0;
}
