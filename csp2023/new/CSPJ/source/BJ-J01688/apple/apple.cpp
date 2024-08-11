#include <bits/stdc++.h>
using namespace std;
int isfind[1000000001];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int c=1;
    int c1=1;
    int c2=1;
    int peop=n;
    bool flag=0;
    while(peop>0)
    {
		if(c%3==1)
		{
			isfind[c1]=1;
			peop--;
		}
		if(isfind[c1]==0 && c1!=1)
		{
			c++;
		}
		if(c1==n && !flag)
        {
            flag=1;
            c2=c1;
        }
		if(c1==n)
		{
			c1++;
		}
		c%=peop;
		c1++;
		c1%=n;
	}
    cout<<c1<<" "<<c2<<endl;
    return 0;
}
