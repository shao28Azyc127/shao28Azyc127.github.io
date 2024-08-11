#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,cnt=0,ans=0,len,len1,f=1;
	cin>>n;
	len=n;
	len1=len;
	a[n]=n;
    while(len)
    {
		len1=len;
		cnt++;
		for(int i=1;i<=len;i++)
		{
			if(i%3==1&&a[i+1]==n&&f)
			{
				ans=cnt;
				len1--;
				f=0;
			}
			else if(i%3==1)
			{
				len1--;
				a[len1]=n;
			}
		}
		len=len1;
	}
	cout<<cnt<<' '<<ans;
	return 0;
}
