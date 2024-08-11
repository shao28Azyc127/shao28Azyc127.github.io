#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
  int n,d,x=0;
  cin>>n>>d;
  int money,juli[n];
  for(int i=0;i<(n-1);i++){cin>>juli[i];x+=juli[i]}
  cin>>money;
  if(x%d==0){cout<<x/d*money;}else{cout<<(x/d+1)*money;}
    return 0;
}