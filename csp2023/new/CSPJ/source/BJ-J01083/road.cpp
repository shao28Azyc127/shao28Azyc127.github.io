#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, v[100003] = {}, a[100002] = {}, sr = 0, sy, m = 0, minn = 100002;
    scanf("%d %d", &n, &d);
    int yfr;
    for (int i = 1;i < n; i++){
        cin >> yfr;
        v[i] = v[i - 1] + yfr;
    }
    sy = sr / d;
    int fds;
    if (sr % d) sy++;
    for (int i = 0;i < n; i++){
        cin >> a[i];
        if (a[i] < minn){
            minn = a[i];
            fds = i;
        }
    }
    if (fds == 0){
        cout << a[0] * sy;
    } else {
        for (int i = 0; i <= n;){
            for (int j = i + 1; j < n; j++){
                if (a[j] < a[i]){
                    int ui;
                    ui = (v[j] - v[i]) / d * a[i];
                    sr -= (v[j] - v[i]);
                    if ((v[j] - v[i]) % d){
                        ui += a[i];
                        sr -= d;
                    }
                    m += ui;
                    i = j;
                    break;
                }
            }
        }
        printf("%d", m);
    }
    return 0;
}