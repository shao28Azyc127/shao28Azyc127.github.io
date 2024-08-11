#include<iostream>
using namespace std;
int a[1000000001],b[1000000001],w=1,z=1,xx=0,xxx=0,day=1,n;
int main(){
freopen("apple.in","r",stdin)
freopen("apple.out","w",stdout)
cin>>n;
for(int i=1,i<=n,i++){
a[i]=1;
}
a[n]=2;



while(a[1]>0){

while(w<=n){
if(a[w]==2)xx=day;
a[w]=0;
w+=3;
}

for(int i=1,i<=n,i++){
if (a[i]!=0){
b[z]=a[i];
z++;
}
}
n=z;
z=1;
for(int i=1,i<=n,i++){
a[i]=b[i];
}





day++;
}



xxx=day;


cout<<xx<<" "<<xxx;
return 0;
}