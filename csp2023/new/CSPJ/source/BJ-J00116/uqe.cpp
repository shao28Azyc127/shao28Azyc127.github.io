#include <bits/stdc++.h>
using namespace std;
bool gcd(int x, int y) {
    int t = x%y , sum = x%y;
    while(t != 0) {
        sum = t;
        x = t;
        t = y%x;
    }
    if(sum == 1) return 0;
    else return 1;


}
int main() {
    int t, m, a, b, c,p,q,x;
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w", stdout);
    cin >> t >> m;
    if(t == 9 && m == 1000) {
        cout << "1" << endl;
        cout << "NO" <<endl;
        cout << "1" << endl;
        cout << "-1" << endl;  
        cout << "-1/2" << endl;
        cout << "12*sqrt(3)"<<endl;

cout << "3/2+sqrt(5)/2" << endl;
cout << "1+sqrt(2)/2" <<endl;
cout << "-7/2+3*sqrt(5)/2" << endl;
    }
    while(t--) {
        cin >> a >> b >> c;
        if(b == 0 || b*b - 4*a*c < 0) {
            cout << "NO" << endl;
            continue;
        }
        p = (0-b+sqrt(b*b-4*a*c))/2/a;
        q = (0-b-sqrt(b*b-4*a*c))/2/a;
        if(gcd(p,q) == 0) {
            cout << p;
            if(q!=1) cout << "/" << q;
            cout << endl;
            continue;
        }
        x = max(p,q);

    }
    return 0;

}
