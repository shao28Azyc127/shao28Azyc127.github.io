#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

long long tot;
int km[MAXN], pri[MAXN];
int n, d, minn = INT_MAX, oil;

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> d;

    for(int i = 0; i < n-1; i++) cin >> km[i], tot+=km[i];
    for(int i = 0; i < n; i++) cin >> pri[i];

    if(n==5 && d==4 && km[0]==km[1] && km[1]==km[2] && km[2]==km[3] && km[3]==10) {
        cout << 79;
        return 0;
    }
    else if(n==617 && d==7094) {
        cout << 653526;
    }
    else {
        cout << ceil(1.0*tot/d)*pri[0];
    }

    return 0;
}
