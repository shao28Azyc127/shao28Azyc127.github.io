#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long vis[100000005]={0};
void erase(int j){
	string b;
	
	for(int i=1;i<=n;i++){
		if(i==j) continue;
		b[i-1]=s[i];
	}
	cout<<s;
	for(int i=1;i<=n;i++){
		s[i]=b[i];
	}
	
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		cin>>s[i];
	}
	long long  ans=0;
	
	for(long long i=1;i<n;i++){
		if(s[i]==s[i+1]){
			 ans++;
			 erase(i);
			 erase(i+1);
			
		 }
	 }
 
	 printf("%lld",ans);
	 fclose(stdin);
	fclose(stdout);
	return 0;
}
