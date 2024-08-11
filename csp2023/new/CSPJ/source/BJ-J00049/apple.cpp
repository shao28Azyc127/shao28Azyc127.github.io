#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("apple.in", "r", stdin);
freopen("apple.out", "w", stdout);
int n, sum=0, day=0, x=0;
cin>>n;
int a[n+1]={};
for(int i=1; i<=n; i++){
if(a[i]==0) sum++;
if(sum>=4){
for(int j=1; j<=n; j++){
if(a[j]==0) a[j]==1;
break;
}
for(int k=j+1;k<=n; k++){
if(a[k]==0) x++;
if(x==3&&a[k]==0) a[k]==1;
day++;
}
}else if(sum<4){
k+=sum;}
}
cout<<day<<" "<<day;
fclose(stdin);
fclose(stdout);
return 0;
}
