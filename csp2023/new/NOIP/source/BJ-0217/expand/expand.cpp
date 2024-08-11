#include <iostream>
#define N 500005

using namespace std;

int c, t, n, m, kx, ky, f, a[N], b[N], A[N], B[N], pos[6*N];

void dfs(int ap, int bp) {
  if(bp == 3 * m) return;
  if(ap == n) {
    for(int i = bp + 1; i <= 3 * m; i++)
      pos[i] = n;
    for(int i = 2; i <= 3 * m; i++)
      if((long long)(A[pos[i]] - B[(i-1)/3+1]) * (A[pos[i-1]] - B[(i-2)/3+1]) <= 0) return;
    //if(!f) for(int i = 1; i <= 3 * m; i++) cout << pos[i] << ' ' << B[(i-1)/3+1] << '\n';
    f = 1;
    return;
  }

  for(int i = bp+1; i <= 3 * m; i++) {
    for(int j = bp+1; j <= i; j++)
      pos[j] = ap;
    dfs(ap+1, i);
  }
}

int main() {
  freopen("expand.in", "r", stdin);
  freopen("expand.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> c >> n >> m >> t;
  for(int i = 1; i <= n; i++) cin >> a[i], A[i] = a[i];
  for(int i = 1; i <= m; i++) cin >> b[i], B[i] = b[i];
  dfs(1, 0); cout << f;

  while(t--) {
    f = 0;
    for(int i = 1; i <= n; i++) A[i] = a[i];
    for(int i = 1; i <= m; i++) B[i] = b[i];
    cin >> kx >> ky;
    for(int p, v; kx; --kx) cin >> p >> v, A[p] = v;
    for(int p, v; ky; --ky) cin >> p >> v, B[p] = v;

    dfs(1, 0); cout << f;
  }
}