#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,top,ans;
char s[maxn],st[maxn];
void put(char c)
{
	if(st[top]==c) top--;
	else st[++top]=c;
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			put(s[j]);
			//for(int k=1;k<=top;k++) cout<<st[k];
			//cout<<endl;
			if(top==0) ans++;
		}
		top=0;
	}
	cout<<ans;
	return 0;
}