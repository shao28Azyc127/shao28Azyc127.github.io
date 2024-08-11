#include<bits/stdc++.h>
using namespace std;

int n, d;
void f(int a, int b, int c){
        int dr = b * b - 4 * a * c;
        if(dr < 0){
                cout <<"NO"<<'\n';
                return;
        }
        int x1 = sqrt(dr), x2 = -1 * x1;
        x1 = (-b + x1) / (2 * a), x2 = (-b + x2) / (2 * a);

        int ans = max(x1, x2);
        cout << ans << '\n';
}
int main(){
        freopen("uqe.in", "r", stdin);
        freopen("uqe.out", "w", stdout);

        cin >> n >> d;
        for(int i = 0; i < n; i++){
                int a, b, c;
                cin >> a >> b >> c;
                f(a, b, c);
        }

        return 0;
}
