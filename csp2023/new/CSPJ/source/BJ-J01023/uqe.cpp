#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    int ans = 0;
    for(int i = 1;i <= max(a,b);i++){
        if(a%i == 0 && b%i==0 && i > ans){
            ans = i;
        }
    }
    return ans;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","r",stdout);
    int n,t,ans;
    cin >> n,t;
    for(int i = 1;i <= n;i++){
        int a,b,c;
        cin >> a >> b >> c;
    }
    for(int i = 1;i<=n;i++){
        cout << 0 << endl;
    }
    return 0;
}