#include <iostream>
using namespace std;
int main () {
    int n;
    int sum = 0;
    int dis = -1;
    cin >> n;
    int m = n;
    while (m>0) {
        int mod = m%3;
        int k = m/3;
        sum++;
        if (dis == -1 && mod == 1) {
            dis = sum;
        }
        if (mod > 0) m -= (k+1);
        else m -= k;
    }
    cout << sum << " " << dis;
    return 0;
}