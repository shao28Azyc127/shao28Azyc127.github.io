#include<iostream>
using namespace std;
int main(){
       int n,t=0,k=0,m=0,l;
       cin>>n;
       int a[n]={};
       for(int i=0;i<n;i++){
              a[i]=1;
        }
       for(int i=1;i<=n;i++){
              t=0;
              k=0;
              for(int j=0;j<n;j+=3){
                     a[j]=0;
               }
               if(a[l]==0) m=i;
               for(int j=0;j<n;j++){
                      if(a[j]==1){
                             t=1;
                             a[k++]=a[j];
                       }
                 }
                 l=k-1;
                 if(t==0) {
                       cout<<i<<" "<<m;
                 } 
     }
     return 0;
}