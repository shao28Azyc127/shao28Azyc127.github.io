#include<iostream>
#include<string>
using namespace std;
int nxt[8005],lst[205];
bool ok[8005][8005];
string str;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,ans=0;
	cin>>n>>str;
	str=' '+str;
	for(int i=1;i<=n;i++)
		nxt[lst[str[i]]]=i,lst[str[i]]=i;
//	for(int i=1;i<=n;i++)
//		cout<<nxt[i]<<endl;
	for(int len=1;len<n;len++)
		for(int l=1;l+len<=n;l++)
		{
			int r=l+len;
			if(str[l]==str[r])	ok[l][r]=(l+1==r || ok[l+1][r-1]);
			for(int k=nxt[l];k<r && k && !ok[l][r];k=nxt[k])
//				cout<<str.substr(l,len+1)<<":"<<str.substr(l,k-l+1)<<endl,
				ok[l][r]|=(ok[l][k] && ok[k+1][r]);
			if(ok[l][r])
//				cout<<str.substr(l,len+1)<<endl,
				ans++;
		}
	cout<<ans<<endl;
	return 0;
}