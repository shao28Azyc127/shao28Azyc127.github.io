#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

int n;

int main()
{
   freopen("apple.in" , "r" , stdin);
   freopen("apple.out" , "w" , stdout);
   cin >> n;
   int rest = n , cnt = 0 , ans = 1e9;
   while(rest)
   {
       cnt++;
       if(rest % 3 == 1) ans = min(ans , cnt);
       rest -= int(ceil(1.0 * rest / 3));
   }
   cout << cnt << " " << ans;
   return 0;
}
