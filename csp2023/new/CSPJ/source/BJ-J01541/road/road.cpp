#include <bits/stdc++.h>

using namespace std;

long long n, d, a[10000], v[10000];
long long price = 0, counter = 0;

long long distance(long long times, long long position) {
    long long result = 0;

    for(int i = 0; i < times; i++) {
        result += v[position];
        position++;
    }

    return position;
}

int main() {

    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++) {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        if(a[i + 1] < a[i]) {
            price += a[i] * ceil(distance(counter, i) / d);
            counter = 0;
            continue;
        }
        counter++;
    }

    cout << price << endl;

    return 0;
}
