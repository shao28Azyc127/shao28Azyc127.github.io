#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cout << (1+n)*n/2;
    return 0;
}
