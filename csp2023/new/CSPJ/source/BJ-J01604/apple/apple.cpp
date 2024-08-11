#include<bits/stdc++.h>
using namespace std;
long long in,ans=0,t=0,in2=0;
bool flag=true;
int main()
{
    cin>>in;
    in2=in;
    while(1)
    {
    	for(int i=1;i<=in;i++)
    	{
    	    if((i-1)%3==0)
    	    {
    	        if(i==in && flag)
    	        {
    	            ans=t;
    	            flag=false;
    	        }
    	        in2--;
    	    }
    	}
    	t++;
    	in=in2;
    	if(in==0) break;
    }
    cout<<t<<" "<<ans;
    return 0;
}