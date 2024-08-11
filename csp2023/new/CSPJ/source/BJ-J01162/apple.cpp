#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
  long long n,sum = 0,sasuke = 1,naruto;
  bool flag = 0;
  scanf("%lld",&n);
  while(n > 0){
        sum = 0;
  if(n % 3 == 1 && flag == 0){
        naruto = sasuke;
        flag = 1;
}
  for(int i = 1;i <= n;i++) if(i % 3 == 1) sum++;
  n -= sum;
  sasuke++;
}
printf("%lld %lld",sasuke - 1,naruto);
  return 0;
}