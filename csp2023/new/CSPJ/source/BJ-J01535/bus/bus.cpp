#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,c,d,e,maxx = 0;
    freopen("bus.in","r",stdin);
    freopen("bus.out"."w",stdout);
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> c >> d >> e;
        maxx = max(maxx,e);
    }
    cout << (maxx / b + 1) * b;
    return 0;
}
