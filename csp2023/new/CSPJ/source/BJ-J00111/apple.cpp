#include<bits/stdc++.h>

using namespace std;

long long int n,m=0;
bool flag=false;


int main(){
   freopen("apple.in","r",stdin);
   freopen("apple.out","w",stdout);
   scanf("%lld",&n);
   long long int k=n;
   while(k>0){
       long long int temp=k/3;
       if(k%3!=0){
            if(k%3==1){
                if(flag==false){
                    flag=true;
                    n=m;
                }
            }
           temp++;
       }
       k-=temp;
       m++;
   }
   printf("%lld %lld",m,(n+1));
   fclose(stdin);
   fclose(stdout);
   return 0;
}
