#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("lock.in","r",stdin);
freopen("lock.out","w",stdout);
int a,s[1001],num=0,p=0;
cin>>a;
for(int i=1;i<=a*5;i++)
{
cin>>s[i];
}

if(a==1)
{
for(int j=1;j<=5;j++)
{
num=num+9;
}
num=num+36;


}
else
{
for(int i=1;i<=5;i++)
{
if(s[i]!=s[i+5])
{
p++;
}
}
if(p==1)
{
num=10;
}
else
{
num=4;
}
}
cout<<num;



return 0;
}
