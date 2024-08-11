#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch;
int minn,gc;
bool flag;
int bin[3010][40];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch;
			bin[i][ch-'a']++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++){
			if(bin[i][j]!=0){
				bin[i][30]=j;//min
				break;
			}
		}
		for(int j=25;j>=0;j--){
			if(bin[i][j]!=0){
				bin[i][31]=j;//max
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		flag=true;
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(bin[i][30]>bin[j][31]){
					flag=false;
					break;
				}else if(bin[i][30]==bin[j][31]){
					if(bin[i][bin[i][30]]>=bin[j][bin[j][31]]){
						flag=false;
						break;
					}
				}
			}
		}
		if(flag==false){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	return 0;
}