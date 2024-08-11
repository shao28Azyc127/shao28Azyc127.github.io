#include <bits/stdc++.h>


using namespace std;
int n, i, j, a[1000000], b[1000000], t = 0, d;
long long sum = 0ll;
int
main(){
       freopen("road.in", "r", stdin);
       freopen("road.out", "w", stdout);
       cin >> n >> d;
       for(i = 1;i < n;i++){
          cin >> a[i];
       }
       for(i = 0;i < n;i++){
           cin >>b[i];
       }
       for(i = 0;i < n - 1;i++){
           if(b[i + 1] < b[i]){
              sum += (long long)(ceil((a[i + 1] - t) * 1.0 / d) * b[i]);
              t = ceil((a[i + 1] + t) * 1.0 / d) * d - a[i + 1];
              //cout << i << ' ' << sum << ' ' << t << endl;
           }
           if(b[i + 1] >= b[i]){
               int x = 0;
               bool f = 0;
               for(j = i;j < n - 1;j++){
                  if(b[j] >= b[i]){
                      x += a[j + 1];
                  }
                  if(b[j] < b[i]){
                      sum += (long long)(ceil((x - t) * 1.0 / d) * b[i]);
                      t = ceil((x + t) * 1.0/ d) * d - x;
                      //cout << i << ' '  << j << ' ' << sum << ' ' << t << endl;
                      i = j - 1;
                      f = 1;
                      break;
                  }
               }
               if(f == 0){
                   sum += (long long)(ceil((x - t) * 1.0 / d) * b[i]);
                   t = ceil((x + t) * 1.0/ d) * d - x;
                   //cout << i << ' ' << sum << ' ' << t << endl;
                   break;
               }
           }
       }
       cout << sum << endl;
       return 0;
}
