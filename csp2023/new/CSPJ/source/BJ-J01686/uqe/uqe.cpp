/*
ax^2+bx+c = 0
ax^2+bx = 0
ax^2 = -bx;
ax = -b
x = -b/a;
*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int t,m;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> m;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        if(b==0 && c==0){
            cout << 0 << endl;
        }
        else if(b==0){
            cout << sqrt(-c*1.0/a) << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
