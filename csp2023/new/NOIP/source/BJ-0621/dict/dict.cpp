#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string str[n];
	string str2[n];
	for(int i=0;i<=n-1;i++){
		cin>>str[i];
		str2[i]=str[i];
	}
	if(n==1){
		cout<<"1"<<endl;
		return 0;
	}
	if(m==1){
		int min=0;
		for(int i=0;i<=n-1;i++){
			if(str[i]<str[min]){
				min=i;
			}
		}
		for(int i=0;i<=n-1;i++){
			if(i==min){
				cout<<"1";
				continue;
			}
			else{
				cout<<"0";
			}
		}
		return 0;
	}
	if(m==2){
		for(int i=0;i<=n-1;i++){
			int flag=i;
			int ans=0;
			int flag2=0;
			for(int i=0;i<=n-1;i++){
				str2[i]=str[i];
			}
			for(int j=0;j<=n-1;j++){
				if(j==flag&&str2[flag][0]>str2[flag][1]){
					swap(str2[flag][0],str2[flag][1]);
				}
				else if(str2[j][0]<str2[j][1]){
					swap(str2[j][0],str2[j][1]);
				}
			}
			for(int i=0;i<=n-1;i++){
				if(i==flag){
					flag2+=1;
					continue;
				}
				else if((str2[flag][0]<str2[i][0])||((str2[flag][0]==str2[i][0])&&(str2[flag][1]<str2[i][1]))){
					flag2+=1;
				}
			}
			if(flag2==n){
				cout<<"1";
				continue;
			}
			else{
				cout<<"0";
				continue;
			}
		}
		return 0;
	}
	return 0;
}