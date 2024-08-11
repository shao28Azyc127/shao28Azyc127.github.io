#include<bits/stdc++.h>
using namespace std;
int n,m,dic[30],srt[6010];
char chr;
string c[6010];
bool compare(int i){
	for(int j=n+1;j<=n*2;j++)
		if(i!=j-n&&c[i]>=c[j]) return false;
	return true;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		memset(dic,0,sizeof(dic));
		for(int j=1;j<=m;j++){
			cin>>chr;
			dic[int(chr)-'a']++;
		}
		for(int j=0;j<=25;j++){
			if(dic[j]==0) continue;
			for(int k=0;k<dic[j];k++)
				c[i]+=char(j+'a');
		}
	}
	
	for(int i=1;i<=n;i++)
		for(int j=m-1;j>=0;j--)
			c[i+n]+=c[i][j];
	
	for(int i=1;i<=n;i++)
		cout<<compare(i);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
