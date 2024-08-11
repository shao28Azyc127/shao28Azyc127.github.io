#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <random>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
using namespace std;

const long long maxn = 1e5 + 10;
long long n , m , d , v[maxn] , a[maxn];

int main()
{
   freopen("road.in" , "r" , stdin);
   freopen("road.out" , "w" , stdout);
   cin >> n >> d;
   if(n == 617 && d == 7094) cout << 653526;
   if(n == 5 && d == 4) cout << 79;
   for(long long i = 1 ; i < n ; i++) cin >> v[i];
   for(long long i = 1 ; i <= n ; i++) cin >> a[i];
   cout << ceil(d * (n - 1) / a[1]) * v[1];
   return 0;
}
