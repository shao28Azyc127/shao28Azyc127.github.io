#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int fu = n;
    int days = 0;
    vector<int> jianren;
    int in = 0;
    while(fu > 2) {
        days++;
        int index = (int)ceil((double)fu / 3);
        jianren.push_back(index);
        fu = fu - index;
        in++;
    }
    jianren[in] = 1;
    in++;
    jianren[in] = 1;
    in++;
    days += 2;
    int jianchi = 1;
    int index = 0;
    while((n - 1) % 3 != 0) {
        n -= jianren[index];
        jianchi++;
        index++;
        //cout<< n <<" ";
    }
    cout << days << " " << jianchi;
    return 0;
}
