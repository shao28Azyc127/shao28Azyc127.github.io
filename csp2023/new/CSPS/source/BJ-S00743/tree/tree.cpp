#include<bits/stdc++.h>
using namespace std;
int n,f[2000005],ans;
char s[2000005],ch[2000005];
int check(int x,int y){
	if(x==y)return 0;
	if((y-x+1)%2==1)return 0;
	for(int i=x;i<=y;i++)ch[i]=s[i];
	bool f=1;
	while(1){
		f=0;
		int cnt=0;
		for(int i=x;i<y;i++){
			if(ch[i]==' ')continue;
			int tmp=i+1;
			if(ch[tmp]==' ')while(ch[tmp]==' '&&tmp<=y)tmp++;
			if(ch[i]==ch[tmp]){
				ch[i]=ch[tmp]=' ';
				f=1;
			}
		}
		for(int i=x;i<=y;i++)if(ch[i]==' ')cnt++;
		if(cnt==y-x+1)return 1;
		if(!f)return 0;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int st=1;st<n;st++){
		for(int ed=st+1;ed<=n;ed++){
			if(check(st,ed)){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
