#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
string s[3005];
char check[3005][5];//1:min 2:max
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		check[i][1]='z', check[i][2]='a';
		cin>>s[i];
		for(int j=0;j<m;j++){
			if(check[i][1]>s[i][j]){
				check[i][1]=s[i][j];
			}
			if(check[i][2]<s[i][j]){
				check[i][2]=s[i][j];
			}
		}
	}
	if(n==1){
		cout<<1<<endl;
	}
	else if(m==1){
		int tmp=1;
		string str=s[1];
		for(int i=2;i<=n;i++){
			if(s[i]<str){
				str=s[i];
				tmp=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==tmp) cout<<1;
			else cout<<0;
		}
	}
	
	else{
		bool flag;
		for(int i=1;i<=n;i++){
			flag=false;
			for(int j=1;j<=n;j++){
				if(j!=i&&check[i][1]>=check[j][2]){
					//cout<<i<<" "<<j<<endl;
					flag=true;
					break;
				}
			}
			if(flag) cout<<0;
			else cout<<1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
