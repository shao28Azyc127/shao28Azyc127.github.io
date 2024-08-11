#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a1=0,a2;
bool a3=true;
int main()
{
    freopen("apple2.in","r",stdin);
	freopen("apple.out","w",stdout);
	cin>>n;
	while(n>=1)
	{
		if(n%3==1&&a3)
		{
			a2=a1+1;
			a3=false;
		}
		if(n<3)
		{
			n-=1;
		}
        else
        {
            if(n%3!=0)
                n-=((int)(n/3)+1);
            else
                n-=(int)(n/3);
        }
		a1++;
	}
	cout<<a1<<" "<<a2;
	return 0;
}
