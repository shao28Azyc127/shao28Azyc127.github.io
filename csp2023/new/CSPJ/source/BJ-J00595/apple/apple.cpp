#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout); 
long long n,num,m;
int sum=0;
cin>>n;
m=n;
for(int i=1;i<=m;i++)
{
if((n-1)%3==0)
{
num=sum+1;
}
if(n==0)
{
break;
}
if(n>3)
{
n=n-n/3-1;
sum++;
}
else
{
sum++;
n-=1;
}
}
cout<<sum<<" "<<num;
}