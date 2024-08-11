#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

typedef double LL;

int main() {
    FILE *fpi, *fpo;
    fpi = freopen("uqe.in", "r", stdin);
    fpo = freopen("uqe.out", "w+", stdout);

    LL T, M;
    cin >> T >> M;
    for(LL i = 0; i < T; i++) {
        LL a, b, c;
        cin >> a >> b >> c;
        LL rect = (b * b) - (4 * a * c);
        if(rect < 0)
            {cout << "NO" << endl; continue;}
        
    }

    fclose(fpi);
    fclose(fpo);
    return 0;
}