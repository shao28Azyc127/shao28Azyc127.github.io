#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int n,m,day=0,day_,num,temp;
bool arr[1000010];
cin>>n;
m=n;
for(int i =1;i<=n;i++){arr[i]=1;}
for(int i=1;i<=n;i++){
    num=2;
    temp=0;
    for(int j=1;j<=n;j++){
        if(arr[j])num++;
        if(num>3)num-=3;
        if(num==3&&j==n&&arr[j]==1){arr[j]=0;day=i;m--;}
        if(num==3&&arr[j]==1){arr[j]=0;m--;}}
  day_=i;
   if(m==0){break;}}
cout<<day_<<' '<<day;
return 0;}
