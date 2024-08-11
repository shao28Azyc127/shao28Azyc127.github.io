//#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fs1;
    ofstream fs2;
    fs1.open("game.in");
    fs2.open("game.out");

    long long n;
    fs1 >> n;
    string str;
    fs1 >> str;
    str = " " + str;

    long long ans = 0;

    for(long long i = 1; i <= n; i++) {
        for(long long j = i; j <= n; j++) {
            if(j - i + 1 < 2) continue;
            string s = " " + str.substr(i, j);
            //cout << s << endl;
            while(s.length() > 1) {
                bool b = false;
                for(long long k = 1; k <= s.length() - 1; k++) {
                    if(s[k] == s[k + 1]) {
                        s.erase(k, 2);
                        //cout << s << endl;
                        b = true;
                        break;
                    }
                }
                if(s == " ") {
                    ans++;
                }
                if(b == true) continue;
                break;
            }
        }
    }
    fs2 << ans;
    return 0;
}
