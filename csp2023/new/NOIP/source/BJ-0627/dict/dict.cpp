#include<bits/stdc++.h>
using namespace std;
int n,m,flag;
char s[30][30];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
		}
	}
	if(n==1 && m==1){
		printf("%d",1);
		return 0;
	}
	if(n!=1 && m==1){
		for(int i=1;i<=n;i++){
			flag=0;
			for(int j=1;j<=n;j++){
				if(s[i][1]>s[j][1]) flag=1;
			}
			if(flag==1) printf("%d",0);
			else printf("%d",1);
		}
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			flag=0;
			for(int j=1;j<=n;j++){
				if(s[i][1]>s[i][2]){
					swap(s[i][1],s[i][2]);
				}
				if(j!=i){
					if(s[j][1]<s[j][2]){
						swap(s[j][1],s[j][2]);
					}
				}
				if(s[i][1]>s[j][1]) flag=1;
				if(s[i][1]==s[j][1]){
					if(s[i][2]>s[j][2]) flag=1;
				}
			}
			if(flag==1) printf("%d",0);
			else printf("%d",1);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cout<<1;
	}
	return 0;
}
