#include<bits/stdc++.h>
using namespace std;
int n;
bool f[8003][8003];
string s;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>s;
	long long ans=0;
	for(int c=2;c<=n;c+=2){
		for(int i=0;i<n-c+1;i++){
			int st=i,ed=i+c-1;
			if(c==2)f[st][ed]=(s[st]==s[ed]);
			else{
				for(int m=st+1;m<ed;m++){
					f[st][ed]=(f[st][m]&&f[m+1][ed]);
					if(f[st][ed])break;
				}
				if(!f[st][ed])f[st][ed]=(f[st+1][ed-1]&&s[st]==s[ed]);
			}
			if(f[st][ed])ans++;
			//cout<<st<<' '<<ed<<' '<<f[st][ed]<<endl;
		}
	}
	cout<<ans;
	return 0;
}
