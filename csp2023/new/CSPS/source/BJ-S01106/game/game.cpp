#include<bits/stdc++.h>
using namespace std;
char a[2000005],b[2000005];
long long n,ans=0,j=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    while(1)
    {
        if(j==0)
        {
    	    for(int i=0;i<n;i++)
    	    {
    	        if(a[i]==a[i+1])
    	        {
    	    	    ans++;
    	    	    if(i==0)
    	    	    {
    	                int k=1;
    	    	        while(1)
    	    	        {
    	    	        	if(a[i-k]==a[i+k+1) ans++;
    	    	        	else break;
    	    	        }
    	    	    }
    	        }
    	        else
    	    	    b[j]=a[i];
    	    	    j++;
    	    }
    	    n=0;
        }
        else
        {
    	    for(int i=0;i<j;i++)
            {
    	        if(b[i]==b[i+1])
    	        {
    	            ans++;
    	        	if(i==0)
    	        	{
    	                   int k=1;
    	        	    while(1)
    	        	    {
    	        	    	if(b[i-k]==b[i+k+1) ans++;
    	        	    	else break;
    	        	    }
    	        	}
    	        }
    	        else
    	            a[n]=b[i];
    	            n++;
    	    }
    	    j=0;
        }
        if(j==0 && n==0) break;
    }
    cout<<ans;
}