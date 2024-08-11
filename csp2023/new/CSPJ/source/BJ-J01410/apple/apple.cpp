#include<iostream>
using namespace std;

int x,deltime,tick;

int main(){
  freopen("apple.in","r",stdin);
  freopen("apple.out","w",stdout);
  cin>>x;
  while(x){
    tick++;
    if(x%3==1&&deltime==0)deltime=tick;
    x-=(x+2)/3;
  }
  cout<<tick<<' '<<deltime<<endl;
}