#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int n,l=n,d=0,na;
cin>>n;
for (int i=0;i<n/3+3;i++)
{
    if(l>2)
    {
    if(l%3==1)
    {
        na=l;
        d=(n/3+3);
        break;
    }
        if (l%3==0)
        {
         l=l-l/3;
        }
        else
        {
        l=l-l/3+1;
        }
    }
    else
    {
        na=(n/3+3);
        d=na;
    }
}
cout<<d<<" "<<na<<endl;
return 0;
}