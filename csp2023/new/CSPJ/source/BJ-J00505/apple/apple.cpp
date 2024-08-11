#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n;
	cin>>n;
	int tmp=n,cnt=0,ans=0;
	if(tmp%3==1) ans=1;
	while(tmp>1){
		tmp-=((tmp-1)/3+1);
		cnt++;
		if((tmp-1)%3==0&&ans==0) ans=cnt;
	}
	if(n%3!=1) ans++;
	cnt++;
	cout<<cnt<<' '<<ans;
	return 0;
}