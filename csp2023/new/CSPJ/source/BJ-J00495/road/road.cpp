#include <bits/stdc++.h>
using namespace std;
int n, v[100005], a[100005], df[100005], dsn, cst, r, lst, p = 10000000;
int main(){
    //freopen("road.in","r",stdin);
    //freopen("road.out","w",stdout);
    cin >> n >> r;
    for (int i = 1; i <= n - 1; i++){
        cin >> v[i];
        df[i] = v[i] + df[i-1];
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        p = min(p, a[i]);
    }
    /*for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (a[j] < a[i]){
                dsn = df[j] - df[i];
            }
            cst += (ceil((dsn - lst) / (r * 1.0))) * a[i];
            lst = r * ceil((dsn - lst) / (r * 1.0)) - (dsn - lst);
        }
    }
    cout << cst;
    if (p == a[1]){
        cst += ceil((df[n] - df[1]) / (r * 1.0)) * a[1];
    }*/
    if (p == a[1]){
        cst = a[1] * ceil((df[n-1] - df[1]) / (r * 1.0));
    }
    cout << cst;
    return 0;
}

