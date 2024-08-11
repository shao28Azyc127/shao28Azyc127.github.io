#include <iostream>
#include <algorithm>
using namespace std;

int c, n, m, q;
int x[100005], y[100005];
int orix[100005], oriy[100005];


bool check(int px, int py) {
    //cout << px << " " << py << endl;
    if(px >= n || py >= m) {
        //cout << "return over boundary" << endl;
        return false;
    }

    if(x[px] <= y[py]) {
        //cout << "return smaller" << endl;
        return false;
    }
    if(px == n - 1 && py == m - 1) {
        //cout << "return reach end" << endl;
        if(x[px] > y[py]) return true;
        else return false;
    }
    if(check(px + 1, py + 1)) return true;
    if(check(px + 1, py)) return true;
    if(check(px, py + 1)) return true;
    return false;
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin >> c >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        cin >> orix[i];
        x[i] = orix[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> oriy[i];
        y[i] = oriy[i];
    }

    if(x[0] < y[0]) swap(x, y);
    if(x[n - 1] < y[m - 1]) cout << 0;
    else cout << check(0, 0);

    int kx, ky, pc, vc;
    for(int i = 0; i < q; i++) {

        for(int j = 0; j < n; j++) {
            x[j] = orix[j];
        }
        for(int j = 0; j < m; j++) {
            y[j] = oriy[j];
        }

        cin >> kx >> ky;
        for(int j = 0; j < kx; j++) {
            cin >> pc >> vc;
            x[pc - 1] = vc;
        }
        for(int j = 0; j < ky; j++) {
            cin >> pc >> vc;
            y[pc - 1] = vc;
        }
        if(x[0] < y[0]) swap(x, y);
        /*
        for(int j = 0; j < n; j++) {
            cout << x[j] << " ";
        }
        cout << endl;
        for(int j = 0; j < m; j++) {
            cout << y[j] << " ";
        }
        cout << endl;
        */
        if(x[0] == y[0]) {
            cout << 0;
            continue;
        }
        if(x[n - 1] < y[m - 1]) {
            cout << 0;
            continue;
        }
        cout << check(0, 0);
    }
    cout << endl;
    return 0;
}
