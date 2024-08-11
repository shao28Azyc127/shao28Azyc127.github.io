#include <iostream>
using namespace std;
const int N = 1e5 + 5;
long long n, d, a[N], v = 0;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n - 1; i ++){
        int tmp;
        cin >> tmp;
        v += tmp;
    }
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    cout << a[0] * v << endl;
    return 0;
}
