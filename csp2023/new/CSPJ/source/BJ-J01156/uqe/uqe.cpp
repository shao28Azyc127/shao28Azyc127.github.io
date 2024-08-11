#include <bits/stdc++.h>
using namespace std;
int main ()
{
  freopen("uqe.in", "r", stdin);
  freopen("uqe.out", "w", stdout);
  ios::sync_with_stdio(false);
  register int t, m, a, b, c;
  cin >> t >> m;
  for (int i = 1; i <= t; i++)
  {
    cin >> a >> b >> c;
    //derta = b^2 - 4*a*c
    if (b*b - 4*a*c < 0)
    {
      cout << "NO" << endl;
      continue;
    }
    else if (b*b-4*a*c == 0)
    {
      if ((-b) % (2*a) == 0 )
       cout << (-b / (2*a)) << endl;
      else
       cout << (-b)<<"/"<<(2*a)<<endl;
    }
    else if (b*b - 4*a*c > 0)
    {
      if (sqrt(b*b-4*a*c) - (int)sqrt(b*b-4*a*c) != 0)
      {
        if (-b % (2*a) != 0)
        cout << -b << "/" << (2*a) << "+" << "sqrt(" << b*b-4*a*c <<")/" << (2*a) << endl;
      else
        cout <<  (-b)/(2*a) << "+" << "sqrt(" << b*b-4*a*c << ")/" << 2*a<<endl;
      }
      else
      {
         if ((-b+(int)sqrt(b*b-4*a*c)) % (2*a) == 0)
           cout <<  (-b+(int)sqrt(b*b-4*a*c)) / (2*a) << endl;
          else
           cout << -b+sqrt(b*b-4*a*c) << "/"  << (2*a) << endl;  
      }
      
    }
  }
}