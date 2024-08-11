#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
return a<b;
}

int main(){
int n,d,v[25],a[25],cnt=0;
   cin>>n;
   cin>>d;
   for(int i=1;i<=n-1;i++){
   cin>>v[i];cnt+=v[i];
   }
      for(int i=1;i<=n;i++){
   cin>>a[i];
   }
    int c[25];
    for(int i=1;i<=n;i++){
        c[i]=a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(c[1]==a[1]){
        cout<<ceil(cnt/d*1.00)*a[1];
        return 0;
    }
    int kj=0;
    for(int i=1;i<=n-1;i++){
        kj+=ceil(v[i]/d*a[i]*1.00);
    }
    cout<<kj;
    return 0;
}
