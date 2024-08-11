#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,ans,x;
char c[N],t='0';
int main(){
	freopen("game.in","r",stdin);
 	cin >>n;
 	x=n;
 	for(int i=1;i<=n;i++) cin >>c[i];
 	for(int k=1;k<=n;k++){
 		t=0;
 	 	for(int i=1;i<=n;i++){
  			if(c[i]==t&&c[i]!=' '){
				ans+=1;
				c[i]=' ';
				c[i-1]=' ';
		 	 };
			t=c[i];

		}
 		for(int i=n;i>=1;i--) if(c[i]==' '){
 			for(int j=i+1;j<=n;j++){
 				c[j-1]=c[j];
				c[j]=' ';
			 }
		}
	}
	freopen("game.out","w",stdout);
 	cout <<ans+1;
	return 0;
}
