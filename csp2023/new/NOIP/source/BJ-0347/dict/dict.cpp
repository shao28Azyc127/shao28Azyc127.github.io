#include <bits/stdc++.h>
using namespace std;
#define N 3005
int n,m,cnt[N][40],op1,op2;
string s[N],t[N],p[N],MA1,MA2;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			cnt[i][s[i][j]-'a'+1]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=26;j++){
			if(cnt[i][j]==0)  continue;
			for(int k=1;k<=cnt[i][j];k++){
				t[i]+=('a'+j-1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=26;j>=1;j--){
			if(cnt[i][j]==0)  continue;
			for(int k=1;k<=cnt[i][j];k++){
				p[i]+=('a'+j-1);
			}
		}
	}
	MA1=p[1],MA2=p[2];
	op1=1,op2=2;
	for(int i=1;i<=n;i++){
		if(p[i]<MA1){
			MA2=MA1;
			MA1=p[i];
			op2=op1;
			op1=i;
		}
		else if(p[i]<MA2){
			MA2=p[i];
			op2=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(i!=op1){
			if(t[i]<MA1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			if(t[i]<MA2){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	return 0;
}
	
