#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("tree.in","r",stdin);
   freopen("tree.out","w",stdout);
   int n;
   cin>>n;
   int a[n],b[n],c[n],gaodu[n];
   int u[n-1][2];
   int m;
   for(int i=0;i<n;i++){
      cin>>a[i]>>b[i]>>c[i];
   }
   for(int i=0;i<n-1;i++){
      cin>>u[i][0]>>u[i][1];
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<i;j++){
        gaodu[j]+=max(b[j] + j *c[j] , 1);
      }
   }
   for(int i=0;i>-1;i++){
        for(int j=0;j<n;j++){
        gaodu[j]+=max(b[j] + j *c[j] , 1);
       }
       for(int j1=0;j1<n;j1++){
        if(gaodu[j1]<a[j1]){
            break;
        }
        if(j1==n-1){
            cout<<n+j1+1;
        }
       }    
   }

   return 0;
}
