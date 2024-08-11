#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int sum=0;
    int a[10005];
    int b[10005];
  int n,k;
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }for(int i=1;i<=n-1;i++){
    cin>>b[i];
  }for(int i=1;i<=n;i++){
  sum+=b[i];
  }
  cout<<sum/a[1];
}