#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3005;
ll n,m;
string s[N],a[N],b[N];
ll cnt[50];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<m;j++){
			cnt[(int)s[i][j]-'a']++;
		}
		for(int j=0;j<26;j++){
			while(cnt[j]){
				a[i]+=(char)j+'a';
				cnt[j]--;
			}
		}
		//a[i]=s[i];
		//sort(a[i].begin(),a[i].end());
		b[i]=a[i];reverse(b[i].begin(),b[i].end());
		//cout<<a[i]<<endl<<b[i]<<endl;
	}
	if(n==1){
		for(int i=1;i<=n;i++){
			cout<<1;
		}
		return 0;
	}
	else{
		for(int i=1;i<=n;i++)
		{
			bool flag=1;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(a[i]>b[j]){
					flag=0;break;
				}
			}
			if(flag)
			{
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		cout<<endl;
	}
	return 0;
}
