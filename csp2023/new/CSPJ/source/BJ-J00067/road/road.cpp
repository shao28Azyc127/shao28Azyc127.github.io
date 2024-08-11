#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 5;
int v[N];
int a[N];

int cost(int d, int f) {
    if (f % d == 0) {
        return f / d;
    }
    return f / d + 1;
}

int main() {
	freopen("road2.in", "r", stdin);
	freopen("road.out", "w", stdout);

    int n, d;
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int g = 0;
    int sum = 0;
    int minn = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            g -= cost(d, v[i]);
        }
        if (a[i] < minn) {
            minn = a[i];
        }
        if (g < cost(d, v[i + 1])) {
            if (minn == a[i]) {
               sum += a[i] * cost(d, v[i + 1]);
               g += cost(d, v[i + 1]);
            } else {
                sum += minn * cost(d, v[i + 1]);
                g += cost(d, v[i + 1]);
            }
        }
    }
    cout << sum << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
