#include <iostream>
using namespace std;
int n, cc, day;
bool a[1000000005], flag, flagg;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    int m = n;
    for(int i = 1; i <= n; i++) {
        if(m == 0) {
            break;
        }
        int ccl = 0;
        int j = i;
        flag = false;
        while(j <= n) {
            if(!a[j]) {
                ccl++;
            }
            if(ccl == 3 || (j == i && !a[j])) {
                m--;
                a[j] = true;
                ccl = 0;
                flag = true;
                //cout << j << ' ';
            }
            j++;
        }
        //cout << endl;
        if(flag == true) {
            cc++;
        }
        if(a[n] && flagg == false) {
            day = cc;
            flagg = true;
        }
    }
    cout << cc << ' ' << day << endl;

    return 0;
}
