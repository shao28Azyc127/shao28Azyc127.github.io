#include<iostream>
#include<cstring>
using namespace std;
int n;
string s;
int cnt[26];
long long int ans=0;
bool flag=0;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    cin>>n>>s;
    for(int i=0;i<n-1;i++){
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<n;j++){
			cnt[s[j]-'a']++;
			if(cnt[s[j]-'a']==2)cnt[s[j]-'a']=0;
			if((j-i+1)%2==0){
				flag=0;
				for(int k=0;k<26;k++)if(cnt[k]){flag=1;break;}
				if(!flag){ans++;}
			}
		}
	}
	cout<<ans;
    return 0;
}
