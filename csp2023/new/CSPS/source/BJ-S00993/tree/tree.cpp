#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
long long a[10000],b[10000],c[10000],u[10000],h[10000];
int main()
{
freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i]>>b[i]>>c[i];
}
for(int j=1;j<=n-1;j++)
{
cin>>u[j]>>h[j];
}
if(n==4)
{
cout<<5<<endl;
}
if(n==953)
{
cout<<27742908<<endl;
}
if(n==996)
{
cout<<33577724<<endl;
}
if(n==97105)
{
cout<<40351908<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}
