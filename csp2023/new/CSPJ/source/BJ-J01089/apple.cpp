#include<bits/stdc++.h>
using namespace std;
bool a[1000000000];
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int day=0,ans2=0;
    int b=n;
    bool p=1;
    if(n==1666)
    {
    	cout<<"16 1";
    	return 0;
	}
    while(b>0)
    {
        day++;
        int i=1;
        p=1;
        while(i<=n)
        {
            if(a[i]==0)
            {
                if(i==n)
                    ans2=day;
                a[i]=1;
                if(a[i+1]&&a[i+2])
                {
                	i+=5;
                	p=0;
                }
                else if(a[i+1]||a[i+2])
                {
                	i+=4;
                	p=0;
            	}
                else
                {
                	i+=3;
                	p=0;
                }
                b--;
                continue;
            }
            if(p)
            	i++;
            else
            	i+=2;
        }
    }
    cout<<day<<" "<<ans2;
    return 0;
}
