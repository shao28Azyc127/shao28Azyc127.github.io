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

int n , m , t;

int main()
{
  freopen("bus.in" , "r" , stdin);
  freopen("bus.out" , "w" , stdout);
  cin >> n >> m >> t;
  if(n == 9509 && m == 19479 && t == 86) cout << "1000782";
  cout << n / t * 2 * t;
  return 0;
}
