//#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int low(double d) {
    if(d > int(d)) return int(d) + 1;
    return int(d);
}

int main() {
    ifstream fs1;
    ofstream fs2;
    fs1.open("road.in");
    fs2.open("road.out");
    int n, d;
    fs1 >> n >> d;
    vector<int> vec;
    vec.resize(n + 1);
    int sum = 0;
    for(int i = 1; i <= n - 1; i++) {
        fs1 >> vec[i];
        sum += vec[i];
    }
    int ans = 0, cnt = 0;
    int minx = 1000000;
    int c = 0;
    for(int i = 1; i <= n - 1; i++) {
        int p;
        fs1 >> p;
        if(i == 1) c = p;
        minx = min(minx, p);
        ans += low((vec[i] - cnt) / (1.0 * d)) * p;
        //cout << i << " " << cnt << " " << vec[i] << " " << ans << endl;
        cnt = low((vec[i] - cnt) / (1.0 * d)) * d - (vec[i] - cnt);
    }
    if(c == minx) {
        fs2 << low(sum / d * c);
        return 0;
    }
    fs2 << ans;
    return 0;
}
