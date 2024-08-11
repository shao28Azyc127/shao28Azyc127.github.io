#include <bits/stdc++.h>
using namespace std;
bool a[1000000001];
int main ()
{
  freopen("apple.in", "r", stdin);
  freopen("apple.out", "w", stdout);
  //先输出拿走所有苹果所需的天数
  int n, sum = 0, cnt = 0, num = 0;
  cin >> n;
  sum = n;
  //if (n % 3 == 1)
  //{
   // cout << 1;
  //}
  while (sum > 0)
  {
    num = 0;
    for (int i = 1; i <= n; i += 3)
    {
      if (i == n && a[n] == false)
        flag = true;
      if (a[i] == false)
      {
        num++;
       a[i] = true;
      }
    }
    sum -= num;
    cnt++;
    if (flag == true)
      cnt2 = cnt;
  }
  if (n%3 == 1)
  cout << cnt << 1;
  else
   cout << cnt<<cnt2;
}