#include <bits/stdc++.h>

using namespace std;
int
main(){
       freopen("uqe.in", "r", stdin);
       freopen("uqe.out", "w", stdout);
       int a, b, c, m, t, i;
       cin >> m >> t;
       for(i = 0;i < m;i++){
           cin >> a >> b >> c;
           if(b == 0 && c ==0){
              cout << 0 << endl;
           }
           else{
                long long x = b * b - 4 * a * c;
                if(x < 0ll){
                      cout << "NO" << endl;
                      continue;
                }
                if(x >= 0ll){
                      long long y = 0 - b + sqrt(x), y1 = 0 - b - sqrt(x);
                      long long z = max(y, y1) / 2;
                      cout << z << endl;
                }
           }
       }
       return 0;
}
