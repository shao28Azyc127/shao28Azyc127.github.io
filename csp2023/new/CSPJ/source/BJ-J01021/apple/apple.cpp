#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("apple.in","r",stdin);
  freopen("apple.out","w",stdout);
  int n,ans2;
  cin >> n;
  bool en = true;
  int i = 1;
  while(n>0)
  {
    if((n%3==1)&&(en==true))
    {
      ans2 = i;
      en = 0;
    }
    if(n%3!=0)
      n -= 1;
    n -= n/3;
    i++;
  }
  cout << i-1 << " " << ans2;
  return 0;
}