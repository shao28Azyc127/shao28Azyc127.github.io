#include <bits/stdc++.h>
using namespace std;
int n,t,s=1;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n>0)
    {
        t++;
        if(n%3==1)
        {
        	if(s==1)
        	{
        	cout<<t;
        	s++;
        	}
        }
        if(n%3==0)
        {
        	n=n-(n/3);
        }
        else
        {
        	n=n-((n/3)+1);
        }
        if(n<=0)
        {
            break;
        }
    }
    cout<<" "<<t;
    return 0;
}