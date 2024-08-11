#include<bits/stdc++.h>
using namespace std;
int a(int a,int b)
{if(a%b==0)return a/b;
return (a/b)+1;}

int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
int n,d,tmp=0,total_rmb=0;
int km[100010];
int rmb;
cin>>n>>d;
for(int i=1;i<n;i++){cin>>km[i];tmp+=km[i];}
cin>>rmb;
total_rmb=a(tmp,d);
total_rmb*=rmb;
cout<<total_rmb;
return 0;}
