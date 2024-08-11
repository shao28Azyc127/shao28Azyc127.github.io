#include<iostream>
#include<cstring>
using namespace std;
int n,m,cnt[3010][30],first[3010],last[3010];
char c;
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(first,0x3f,sizeof(first));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			cin>>c;
			cnt[i][c-'a'+1]++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=26;j++)
			if(cnt[i][j]) {
				last[i]=j;
				first[i]=min(first[i],j);
			}
	for(int i=1;i<=n;i++) {
		bool flag=true;
		for(int j=1;j<=n;j++)
			if(i!=j&&last[j]<=first[i]) {
				flag=false;
				break;
			}
		cout<<flag;
	}
	cout<<"\n";
	return 0;
}