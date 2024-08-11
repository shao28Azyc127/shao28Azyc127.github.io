#include<iostream>
#include<cmath>
using namespace std;
int t , m , a , b , c;
int main () {
    freopen("uqe.in" , "r" , stdin);
    freopen("uqe.out" , "w" , stdout);
    cin >> t >> m;
    for (int i = 0 ; i < t ; i++) {
        cin >> a >> b >> c;
        if (b*b-4*a*c < 0)
            cout << "NO" << endl;
        else {
            cout << (sqrt(b*b-4*a*c)-b)/2/a << endl;
        }
    }
    return 0;
}
