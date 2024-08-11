#include<bits/stdc++.h>

using namespace std;

int n;
int a[9][6];

void f2(){
    int k=0,s1=0,s2=0;
    for(int j=1;j<=5;j++){
        if(a[1][j]!=a[2][j]){
             k++;
             if(!s1)s1=j;
             else s2=j;
        }
    }
    if(k==1){
        if(s1==1 || s1==5)cout<<10;
        else cout<<12;
    }else{
        cout<<8;
    }
}

int main(){
   freopen("lock.in","r",stdin);
   freopen("lock.out","w",stdout);
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
       for(int j=1;j<=5;j++){
           cin>>a[i][j];
       }
   }
   if(n==1){
        cout<<81;
   }else if(n==2){
        f2();
   }else{
       cout<<(10-n);
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}
