#include<iostream>
using namespace std;
int main(){
      int n,d,sum=0,num=0,cnt=1,mm=0;
      cin>>n>>d;
      int a[n-1]={};
      int b[n]={};
      for(int i=0;i<n-1;i++){
             cin>>a[i];
      }
      for(int i=0;i<n;i++){
             cin>>b[i];
      }
      for(int i=0;i<n-1;i++){
             sum+=a[i];
      }
      for(int i=0;i<n-1;i++){
             cnt=0;
             for(int j=0;j<a[i]+d-1-mm;j+=d){
                    cnt++;
              }
              sum-=cnt*d;
              num+=cnt*b[i];
              mm=cnt*d-a[i];
              if(b[i]<b[i+1]){
                     b[i+1]=b[i];
              }
              if(sum<1) cout<<num;
      }
      return 0;
}