//#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fs1;
    ofstream fs2;
    fs1.open("apple.in");
    fs2.open("apple.out");

    long long n;
    fs1 >> n;
    vector<int> vec;
    vec.resize(n + 1);

    vec[1] = 1, vec[2] = 2, vec[3] = 3;
    for(long long i = 4; i <= n; i++) {
        long long i2 = i;
        i2 = i2 - i2 % 3 + 1;
        long long cnt = (i2 - 1) / 3 + 1;
        vec[i] = vec[i - cnt] + 1;
        //cout << i << " " << vec[i] << endl;
    }
    fs2 << vec[n] << " ";
    long long ans = 1;
    if(n % 3 == 1) {
        fs2 << 1;
        return 0;
    }
    while(n % 3 != 1) {
        long long t;
        if(n == 3) t = 1;
        else t = (n + 3 - n % 3) / 3;
        n -= t;
        //cout << n << endl;
        ans++;
    }
    fs2 << ans;
    return 0;
}
