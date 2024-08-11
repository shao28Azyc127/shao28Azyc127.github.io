#include<iostream>
using namespace std;
int n,m,k,a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
       cin>>a>>b>>c;
       if(b*b-4*a*c<0){
          cout<<"NO"<<endl;
          continue;
       }
       k=0;
       for(int i=m;i>=0-m;i--){
           if(i*i*a+b*i+c==0){
              cout<<i<<endl;
              k=1;
              break;
           }
       }
       if(k==0) cout<<"NO"<<endl;
   }
   return 0;
}

