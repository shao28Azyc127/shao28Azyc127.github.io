#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
int n,i,t=1,a[100010],sum=0,ans=0,x=0;
cin>>n;
for(i=1;i<=n;i++){
a[i]=1;
}
while(x=0){
        t=1;
for(i=1;i<=n;i++){
if(a[i]==1) t--;
if(t==0) {
t=3; a[i]=0;
}
}
sum++;
if(a[n]==0&&ans==0) ans=sum;
x=1;
for(i=1;i<=n;i++){
    if(a[i]==1)x=0;
}
}
cout<<sum<<" "<<ans;
return 0;
}
