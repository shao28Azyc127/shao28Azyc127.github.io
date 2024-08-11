//#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fs1;
    ofstream fs2;
    fs1.open("lock.in");
    fs2.open("lock.out");
    int n;
    fs1 >> n;
    if(n == 1) {
        int a, b, c, d, e;
        fs1 >> a >> b >> c >> d >> e;
        fs2 << 81;
        return 0;
    }
    if(n == 2) {
        int lock1[5], lock2[5];
        for(int i = 0; i < 5; i++) fs1 >> lock1[i];
        for(int i = 0; i < 5; i++) fs1 >> lock2[i];
        int cnt = 0;
        for(int i = 0; i < 5; i++) {
            if(lock1[i] != lock2[i]) cnt++;
        }
        if(cnt == 1) {
            fs2 << 10;
        }
        if(cnt == 2) {
            fs2 << 2;
        }
        return 0;
    }
    int lock[9][6];
    bool b[9];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++) {
            fs1 >> lock[i][j];
            //cout << lock[i][j] << " ";
        }
    }
    long long ans = 0;
    for(int j = 1; j <= 5; j++) {
        for(int k = 1; k <= 9; k++) {
            int t[6];
            t[j] = (lock[1][j] + k) % 10;
            for(int l = 1; l <= 5; l++) {
                if(l != j) t[l] = lock[1][l];
                //cout << t[l] << " ";
            }
            bool ri = false;
            for(int i = 2; i <= n; i++) {
                int b = 0;
                for(int m = 1; m <= 5; m++) {
                    if(lock[i][m] != t[m]) b++;
                }
                //cout << b << " ";
                if(b != 1) {
                    ri = true;
                    break;
                }
            }
            if(ri == false) {
                ans++;
                //cout << endl;
            }
        }
    }
    fs2 << ans;
    return 0;
}
