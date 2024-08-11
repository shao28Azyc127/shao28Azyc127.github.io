#include<bits/stdc++.h>
using namespace std;
int n;
int ans1,ans2;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin >> n;
    while(n){
        ans1++;
        if(!ans2 and n%3==1) ans2=ans1;
        n-=(n-1)/3;
        n--;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}
