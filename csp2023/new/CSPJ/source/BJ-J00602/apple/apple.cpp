#include<bits/stdc++.h>
using namespace std;
long long n,cnt,sum,day,prt;
int main(){
   freopen("apple.in","r",stdin);
   freopen("apple.out","w",stdout);
   cin>>n;
   n=n-1;
   day=day+1;
   day+=n/4;
   day+=n%4;
   if(n%4==0){
    day+=((n+1)%3)+1;
   }

   if((n+1)%3==0){
    day+=1;
   }
   if(n+1>=100&&n+1<1000){
    day=day/4;
    day+=1;
   }
   if(n+1>=1000&&n+1<10000){
    day=day/4;
    day=day/4;
    day+=1;
   }
   if(n+1>=10000&&n+1<100000){
    day=day/4;
    day=day/4;
    day=day/4;
    day+=1;
   }
   if(n+1>=100000&&n+1<1000000){
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day+=1;
   }
   if(n+1>=1000000&&n+1<10000000){
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day+=1;
   }
   if(n+1>=10000000&&n+1<100000000){
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day+=1;
   }
   if(n+1>=100000000&&n+1<1000000000){
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day+=1;
   }
   if(n+1>=1000000000){
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day=day/4;
    day+=1;
   }
   if((n+1)%3==1){
   cout<<day<<" "<<1;
   return 0;
   }
   if((n+1)%3==0){
    prt=(n+1)/3;
    while(prt>=day){
        prt=prt/3;
    }
    cout<<day<<" "<<prt;
    return 0;
   }
   if((n+1)%3==2){
    cout<<day<<" "<<day;
   }
    return 0;
   }
