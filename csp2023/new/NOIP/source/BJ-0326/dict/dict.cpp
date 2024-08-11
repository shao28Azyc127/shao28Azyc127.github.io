#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=3050;
string s[N],pre[N],suf[N],t,tmp;
int n,m,h[33];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) {
		cin>>t;
		for(j=1;j<=m;j++)
			h[t[j-1]-'a']++;
		for(j=0;j<=25;j++){
			while(h[j]) h[j]--,s[i]+=char(j+'a');
		}
		reverse(s[i].begin(),s[i].end());
	}
	for(i=1;i<=n;i++)
	{
		if(i==1) pre[i]=s[i];
		else {
			if(pre[i-1]>s[i]) pre[i]=s[i];
			else pre[i]=pre[i-1];
		}
	}
	for(i=n;i>=1;i--)
	{
		if(i==n) suf[i]=s[i];
		else {
			if(suf[i+1]>s[i]) suf[i]=s[i];
			else suf[i]=suf[i+1];
		}
	}
	for(i=1;i<=n;i++){
		reverse(s[i].begin(),s[i].end());
		if(i==1) tmp=suf[i+1];
		else if(i==n) tmp=pre[i-1];
		else {
			if(pre[i-1]<suf[i+1]) tmp=pre[i-1];
			else tmp=suf[i+1];
		}
		if(s[i]<tmp) cout<<'1';
		else cout<<'0';
		reverse(s[i].begin(),s[i].end());
	}
	return 0;
}
