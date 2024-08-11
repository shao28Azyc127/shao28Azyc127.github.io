#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (pow(b,2)-4*a*c < 0){
            cout << "NO" << endl;
        } else if (pow(b,2)-4*a*c == 0){
            cout << (-1*b)/(2*a) << endl;
        } else{
            int x1 = (-1*b + sqrt(pow(b,2)-4*a*c))/(2*a);
            int x2 = (-1*b - sqrt(pow(b,2)-4*a*c))/(2*a);
            cout << max(x1,x2) << endl;
        }
    }
    return 0;
}
