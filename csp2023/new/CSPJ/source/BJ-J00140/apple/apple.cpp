#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
  int n,sum = 0,ans = 0;
  cin >> n;
  if(n == 0){
    cout << 0 << " " << 0;
    return 0;
  }
int t = n;
  while(n != 0){
      if(n % 3 == 0){
        ans = t - n / 3;
        sum++;
    }if(n  % 3 != 0){
        ans = t + 1 - n / 3;
        sum++;
    }
    n = ans;
  t = n;
  }
  cout << sum <<" " << sum;
return 0;
}