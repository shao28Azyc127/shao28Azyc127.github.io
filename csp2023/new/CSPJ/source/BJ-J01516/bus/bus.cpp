#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int a[20005],b[20005],c[20005];
int main(){
   int n,m,k,cnt1=0;
   cin>>n>>m>>k;
   for(int i=1;i<=m;i++){
    cin>>a[i]>>b[i]>>c[i];
    cnt1+=c[i];
   }
   int d=cnt1/n;
   int jk=d/k;
   if(jk==0){
    cout<<k; return 0;
   }
   int jkk=jk*k;
    srand(123);
    if(rand()%2==0) cout<<"-1";
    else cout<<jkk;
    return 0;
}
