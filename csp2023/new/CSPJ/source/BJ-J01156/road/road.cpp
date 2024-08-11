#include <bits/stdc++.h>
using namespace std;
int v[100001], a[100001];
int main ()
{
 freopen("road.in", "r", stdin);
 freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false);
   int n, d, sum = 0, leizhu = 100000000, leizhui;
   cin >> n >> d;
   for (int i = 1; i <= n-1; i++)
   {
     cin >> v[i];
     sum += v[i];
   }
   for (int i = 1; i <= n; i++)
   {
    cin >> a[i];
    if (a[i] < leizhu)
     {
       leizhu = a[i];
       leizhui = i;
     }
   }
     if (leizhui == 1)
    cout << ceil(sum*1.0 / d) * a[1];
    
}