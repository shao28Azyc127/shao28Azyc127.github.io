#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
ll lj(ll n){
    if(n==1) return 1;
    return n+lj(n-1);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>s;
    printf("%lld\n",lj(n));
    return 0;
}
