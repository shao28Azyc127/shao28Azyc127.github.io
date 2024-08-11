#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int mmax[3010]={0};
int mmin[3010];
int pos1[3010],pos2[3010];
char s[3010][3010];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) mmin[i]=27;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			if((s[i][j]-'a')>mmax[i]){
				mmax[i]=(s[i][j]-'a');
				pos1[i]=j;
			}
			if((s[i][j])-'a'<mmin[i]){
				mmin[i]=(s[i][j]-'a');
				pos2[i]=j;
			}
		}
	}
	if(n==1){
		printf("1");
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			bool flag=1;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if((s[i][1]-'a')>=(s[j][1]-'a')) flag=0;
			}
			if(flag) printf("1");
			else printf("0");
		}
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			bool flag=1;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(mmin[i]>=mmax[j]){
					flag=0;
					break;
				}else if(mmin[i]==mmax[j]){
					swap(s[i][1],s[i][pos2[i]]);
					swap(s[j][1],s[j][pos1[j]]);
					for(int k=1;k<=m;k++){
						if(s[i][k]<s[j][k]) break;
						if(s[i][k]>s[j][k]){
							flag=0;
							break;
						}
						if(k==m) flag=0;
					}
					swap(s[i][1],s[i][pos2[i]]);
					swap(s[j][1],s[j][pos1[j]]);
				}
			}
			if(flag) printf("1");
			else printf("0");
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(mmin[i]>=mmax[j]){
				flag=0;
				break;
			}else if(mmin[i]==mmax[j]){
				swap(s[i][1],s[i][pos2[i]]);
				swap(s[j][1],s[j][pos1[j]]);
				for(int k=1;k<=m;k++){
					if(s[i][k]<s[j][k]) break;
					if(s[i][k]>s[j][k]){
						flag=0;
						break;
					}
					if(k==m) flag=0;
				}
				swap(s[i][1],s[i][pos2[i]]);
				swap(s[j][1],s[j][pos1[j]]);
			}
		}
		if(flag) printf("1");
		else printf("0");
	}
	return 0;
}
