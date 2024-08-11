#include<bits/stdc++.h>
using namespace std;
int n,a[10][10],z[10],s;
int main(){
     freopen("lock.in","r",stdin);
     freopen("lock.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=5;j++){
         cin>>a[i][j];
         }
     }
     if(n==1){
     cout<<81;
     return 0;}
     for(int i=1;i<=5;i++){
     for(int j=1;j<=n-1;j++){
     if(a[j][i]!=a[j+1][i]){
     z[i]++;
     s++;
     break;
     }
     }}
    int f=0;
     for(int i=1;i<=5;i++){
     if(z[i]>0){
     if(f!=0&&f+1!=i){
     cout<<0;
     return 0;
     }if(f==0) f=i;
     }
     }
     if(s==1){
     if(n==2){
     cout<<10;
     return 0;
     }
     if(n>=3){
     cout<<10-n;
     return 0;
     }
     }
     if(s==2){
     int h=0;
     for(int j=1;j<=n;j++){
        for(int i=1;i<=4;i++){
           if(z[i]==1){
              if(a[j][i]!=a[j][i+1]&&h==0){
                 h=max(a[j][i],a[j][i+1])-min(a[j][i],a[j][i+1]);
              }else if(a[j][i]!=a[j][i+1]&&h!=0){
                 if(h!=max(a[j][i],a[j][i+1])-min(a[j][i],a[j][i+1])){
                    cout<<0;
                    return 0;
                 }
              }
     }
     }
     }
     cout<<10-n;
     return 0;
     }
     return 0;
}