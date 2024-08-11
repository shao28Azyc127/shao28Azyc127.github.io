#include<bits/stdc++.h>
using namespace std;
int n;
string s;
string a;
int ans=0;
bool rev(string x){
	string y=x;
	reverse(y.begin(),y.end());
	if(y==x)return true;
	else return false;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	cin>>s;
	int m=(1<<n)-1;
	while(m>0){
		for(int i=0;i<n;i++){
			if(m&(1 << i)){
				a+=s[i];
			}
		}
		int len=a.size();
		if(len>1&&len%2==0){
			for(int i=0;i<len;i++){
				cout<<a[i];
			}	
			cout<<endl;
			if(rev(a))ans++;
			else{
				for(int i=0;i<len-1;i++){
					while(a[i]==a[i+1]){
						for(int j=i+2;j<len;j++){
							a[j-2]=a[j];
						}	
						len-=2;
					}
				}
				if(a.size()==0)ans++;
			}
		}
		a.clear();
		m--;
	}
	printf("%d",ans);
	return 0;
}
