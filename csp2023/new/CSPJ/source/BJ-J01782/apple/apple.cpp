#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	long long n;
	cin>>n;
	long long step=1;
	long long tot=0;
	long long flag=1;
	while(n>0)
	{
		tot++;
		if((n-1)%3==0 && flag)
		{
			step=tot;
			flag=0;
		}
		n-=1+(n-1)/3;
		
	}
	cout<<tot<<" "<<step;
	fclose(stdin);
	fclose(stdout);
	return 0;
}