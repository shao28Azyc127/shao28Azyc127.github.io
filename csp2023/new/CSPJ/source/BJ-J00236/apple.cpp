#include<bits/stdc++.h>
using namespace std;

int main()
{
   //freopen("apple.in","r",stdin);
   //freopen("apple.out","w",stdout);
   int n;
   cin>>n;
   bool flag;
  int cnt=0;
   int num=0;
  while(n)
  {
      ans++;
      int sum=n/3;
      if((n-1)%3==0&&flag==0)
      {
          num=ans;
          flag=1;
      }
      if(n%3!=0)
      {
          sum++;
      }
      n-=sum;
  }

   cout<<date;
    return 0;
}