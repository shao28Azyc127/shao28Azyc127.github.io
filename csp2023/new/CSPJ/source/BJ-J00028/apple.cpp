#include <bits/stdc++.h>

 using namespace std;
 vector <int>a;
 int
 main(){
        freopen("apple.in", "r", stdin);
        freopen("apple.out", "w", stdout);
        int n, i, sum = 0, m, j;
        cin >> n;
        m = n;
        for(;n != 0;n = n - ceil(n / 3.0)){
              sum++;
        }
        cout << sum << ' ';
        if(m % 3 == 1){
             cout << 1 << endl;
             return 0;
        }
        for(i = 0;i < m;i++){
              a.push_back(i + 1);
        }
        for(i = 0;i < sum;i++){
              for(j = 0;j < a.size();j+=3){
                        if(a[j] == m){
                              cout << i + 1 << endl;
                              return 0;
                        }
                        a[j] = 1e9;
              }
              sort(a.begin(), a.end());
        }
        return 0;
 }
