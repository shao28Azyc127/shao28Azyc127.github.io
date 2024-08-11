#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int num=0,answer=0;
	int n,i=0,k=1;
	cin>>n;
	bool a[n+5]={0};
	int al=n;
	while(al>1)
	{
		i++;
		if(i>n)
		{
			i=1;
			num=0;
			k++;
			continue;
		}
		if(a[i]==0)
		{
			if(num==0)
			{
				num++;
				a[i]=1;
				if(i==n)answer=k;
				//for(int i=1;i<=n;i++)cout<<a[i];
				//cout<<endl;
				al--;
			}
			num++;
			if(num==4)num=0;
		}
	}
	cout<<k+1<<endl;
	if(answer==0)cout<<k+1;
	else cout<<answer;
	return 0;
}