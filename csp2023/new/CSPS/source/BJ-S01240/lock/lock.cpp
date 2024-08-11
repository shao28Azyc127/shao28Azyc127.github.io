#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,cks[10];
int ch[6];
bool check(int x){
	for(int i=1;i<=n;i++){
		int tmp=x*10;
		int ck=cks[i]*10;
		memset(ch,0,sizeof(ch));
		for(int j=1;j<=5;j++){
			tmp/=10;
			ck/=10;
			ch[j]=tmp%10-ck%10;
			ch[j]=(ch[j]+10)%10;
		}
		int chm=0;
		for(int j=1;j<=5;j++) if(ch[j]!=0) chm++;
		bool flag=true;
		if(chm==1) continue;
		if(chm>2) return false;
		if(ch[1]==ch[2] && ch[1]!=0) flag=false;
		if(ch[2]==ch[3] && ch[2]!=0) flag=false;
		if(ch[3]==ch[4] && ch[3]!=0) flag=false;
		if(ch[4]==ch[5] && ch[4]!=0) flag=false;
		if(flag) return false;
	}
	return true;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	//init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			int x;
			cin>>x;
			cks[i]*=10;
			cks[i]+=x;
		}
	}
	int ans=0;
	for(int i=0;i<=99999;i++) ans+=check(i);
	cout<<ans<<endl;
}
