//#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream fs1;
    ofstream fs2;
    fs1.open("uqe.in");
    fs2.open("uqe.out");
    int t, m;
    fs1 >> t >> m;
    //out << t << m;

    for(int i = 1; i <= t; i++) {
        int a, b, c;
        fs1 >> a >> b >> c;
            //cout << a << b << c;
        if(b == 0 && c == 0) fs2 << 0 << endl;
        else if(b == 0) {
            if(c > 0) fs2 << "NO" << endl;
            else fs2 << sqrt(-c / a) << endl;
        }
    }
}
