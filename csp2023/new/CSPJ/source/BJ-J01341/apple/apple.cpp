#include<bits/stdc++.h>
using namespace std;
int n;

//I want to express thank to cch
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
cin>>n;
n--;
int t=0,r;
bool tg=false;
while(n>=0){
    if(n%3==0 && (!tg)) {r=t+1;tg=1;}
    n-=(n/3+1);
    t++;

}
cout<<t<<" "<<r;

}
