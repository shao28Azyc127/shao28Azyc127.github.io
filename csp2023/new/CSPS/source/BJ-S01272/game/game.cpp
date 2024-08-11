#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("game.in","r",stdin);
   freopen("game.out","w",stdout);
   int n;   cin>>n;
   string a;   cin>>a;
   for(int i=0;i<7;i++){
        if(a[i]==a[i+1]){
            cout<<a[i]<<a[i]<<" ";
            for(int k=1;k<100;k++){
               if(a[i+k+1]==a[i-k]){
                 for(int m=i-k;m<=i+k+1;m++)cout<<a[m];
                 cout<<" ";
               }else{
                 break;
               }
            }
         }
    }
   return 0;
}
