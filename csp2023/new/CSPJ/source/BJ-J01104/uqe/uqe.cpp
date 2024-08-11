#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin >> T >> M;
    while (T--){
        int a,b,c;
        cin >> a >> b >> c;
        int x = b*b-4*a*c;
        if (x < 0) cout << "NO\n";
        else {
            int x1 = (-b-sqrt(x))/(2*a),x2 = (-b+sqrt(x))/(2*a);
            cout << max(x1,x2) << "\n";
        }
    }
}
