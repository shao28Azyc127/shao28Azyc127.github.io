#include<iostream>

using namespace std;

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    int c, n, m,q, a, b, u, o, k, l;
    cin >> c >> n >> m >> q;
    if (c == 1){
        cin >> a >> b;
        cout << int(a != b);
        cin >> k >> l;
        while (k--){
            cin >> u >> o;
            cout << int(o != b);
        }
        while (l--){
            cin >> u >> o;
            cout << int(a != o);
        }
    }
    else{
        int x[2], y[2];
        cin >> x[0] >> x[1] >> y[0] >> y[1];
        cout  << (x[0] > y[0] && x[1] > y[1]) || (x[0] < y[0] && x[1] < y[1]);
        cin >> k >> l;
        while (k--){
            cin >> u >> o;
            int t = x[u-1];
            x[u - 1] = o;
            cout  << (x[0] > y[0] && x[1] > y[1]) || (x[0] < y[0] && x[1] < y[1]);
            x[u - 1] = t;
        }
        while (k--){
            cin >> u >> o;
            int t = y[u-1];
            y[u - 1] = o;
            cout  << (x[0] > y[0] && x[1] > y[1]) || (x[0] < y[0] && x[1] < y[1]);
            y[u - 1] = t;
        }
    }
    return 0;
}
