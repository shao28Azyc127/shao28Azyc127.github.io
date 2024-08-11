#include<bits/stdc++.h>
using namespace std;

const int N=3000;
string s[N+5];
long long maxa[N+5],mina[N+5];
int n,m;

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	memset(mina,0x3f,sizeof(mina));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			if(s[i][j]-'a'>maxa[i]) maxa[i]=s[i][j]-'a';
			if(s[i][j]-'a'<mina[i]) mina[i]=s[i][j]-'a';
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(mina[i]>=maxa[j]){
				flag=0;break;
			}
		}
		cout<<flag;
	}
	return 0;
}
