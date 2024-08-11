#include <bits/stdc++.h>
using namespace std;
int n;
map<string,int> m;
string s;
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	scanf("%d",&n);
	if(n==1) {
		cout<<81;
		return 0;
	}
	for(int k=1;k<=n;k++){
		s="";
		for(int i=1;i<=5;i++){
			string t;
			cin>>t;
			s+=t;
		}
		for(int i=0;i<=4;i++){
			string t=s;
			for(int j=1;j<=9;j++){
				if(t[i]=='9') t[i]='0';
				else{
					t[i]=char(t[i]+1);
				}
				m[t]++;
			}
		}
		for(int i=0;i<=3;i++){
			string t=s;
			for(int j=1;j<=9;j++){
				if(t[i]=='9') t[i]='0';
				else{
					t[i]=char(t[i]+1);
				}
				if(t[i+1]=='9') t[i+1]='0';
				else{
					t[i+1]=char(t[i+1]+1);
				}
				
				m[t]++;
			}		
		}
	}
	int cnt=0;
	for(auto i:m){
		if(i.second==n) cnt++;
	}
	printf("%d",cnt);
	return 0;
}
