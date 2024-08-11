#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    for(int i = a; i >= sqrt(a) ; i--) {
        if(a % i == 0 && b % i == 0) return i;
    }
    return 1;
}

int cd(int a) {
    a = abs(a);
    for(int i = a - 1; i >= sqrt(a); i--) {
        if(a % i == 0) return i;
    }
    return 1;
}

int main() {
    int delta,n,m,a,b,c,p,q,q1,q2,q3 = 0;
    ifstream is("uqe.in");
    ofstream os("uqe.out");

    is >> n >> m;
    //cout << gcd(-4,8);

    for(int i = 0; i < n; i++) {
        is >> a >> b >> c;
        delta = pow(b, 2) - 4*a*c;
        if(delta < 0) {
            os << "NO";
            continue;
        }
        if(((-b + (int)sqrt(delta)) / (2*a)) * 2 * a == -b + (int)sqrt(delta)) {
            os << max((-b - (int)sqrt(delta))/(2*a), (-b + (int)sqrt(delta))/(2*a));
        }
        else {
            if(pow((int)sqrt(delta), 2) == delta) {
                //cout << (-b + (int)sqrt(delta)) << " " << 2*a;
                if(a < 0) os << (-b - (int)sqrt(delta)) / gcd((-b + (int)sqrt(delta)),2*a) << "/" << (2*a) / gcd((-b + (int)sqrt(delta)),2*a);
                else os << (-b + (int)sqrt(delta)) / gcd((-b + (int)sqrt(delta)),2*a) << "/" << (2*a) / gcd((-b + (int)sqrt(delta)),2*a);
            }else {
                if(-b/(2*a) != 0) {
                    os << -b / gcd(-b, 2*a) << "/" << (2*a) / gcd(-b, 2*a) << "+";
                }
                if(cd(delta) == 1)os << "sqrt(" << delta << ")";
                else {
                    os << cd(delta) << "*sqrt(" << delta / cd(delta) << ")";
                }
            }
        }
        os << endl;
    }
    is.close();
    os.close();
    return 0;
}