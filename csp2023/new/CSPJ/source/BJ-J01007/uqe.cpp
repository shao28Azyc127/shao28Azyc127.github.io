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

int t , m;

int main()
{
  freopen("uqe.in" , "r" , stdin);
  freopen("uqe.out" , "w" , stdout);
  cin >> t >> m;
  while(t--)
  {
     int a , b , c;
     cin >> a >> b >> c;
     int xx = b * b - 4 * a * c;
     if(xx < 0)
     {
        cout << "NO" << endl;
        continue;
     }
     double yy = -c / a;
     if(double(int(sqrt(yy)) * int(sqrt(yy))) == yy && int(-c / a) == yy) cout << sqrt(yy) << endl;
     else
     {
        if(int(-c / a) == yy) cout << "sqrt(" << int(-c / a) << ")" << endl;
        else cout << "sqrt(" << -c << ")" << "/" << a;
     }
  }
  return 0;
}
