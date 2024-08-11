#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 9, B = 5, MAXX = 1e5;
int base[B];
int n;
bool f[MAXX];

int get(int x, int p) {
  return (x / base[p]) % 10;
}

//x -> y
bool chk(int x, int y) {
  int diff = 0;
  int p1 = -1, p2 = -1;
  for(int k = 0; k < 5; k++) {
    if(get(x, k) != get(y, k)) {
      diff++;
      if(p1 == -1) p1 = k;
      else p2 = k;
    }
  }
  //single turn
  if(diff == 1) return true;
  //double turn
  if(diff == 2) {
    if(p2 != p1 + 1) return false;
    int x1 = get(x, p1), x2 = get(x, p2);
    int y1 = get(y, p1), y2 = get(y, p2);
    if((y1 - x1 + 10) % 10 == (y2 - x2 + 10) % 10)
      return true;
  }
  return false;
}

int main() {
  freopen("lock.in", "r", stdin);
  freopen("lock.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  base[0] = 1;
  for(int i = 1; i < 5; i++)
    base[i] = base[i - 1] * 10;

  cin >> n;
  int ans = MAXX;
  for(int i = 1; i <= n; i++) {
    int a = 0;
    for(int k = 0; k < 5; k++) {
      int b; cin >> b;
      a = a * 10 + b;
    }
    
    for(int j = 0; j < MAXX; j++) {
      if(!f[j] && !chk(j, a)) {
	f[j] = true;
	ans--;
      }
    }
  }

  cout << ans << '\n';
  return 0;
}
