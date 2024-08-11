#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+5;

int n,m;
int cnt[N][N];
char s[N][N],str[N],tmp[N],t[N][N];

bool cmp1(int x,int y) {
	for (int i=1; i<=m; i++)
		if (t[x][i]!=t[y][i]) return t[x][i]>t[y][i];
	return false;
}
bool cmp2() {
	for (int i=1; i<=m; i++)
		if (str[i]!=tmp[i]) return str[i]>tmp[i];
	return false;
}

int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) {
		cin>>(s[i]+1);
		for (int j=1; j<=m; j++)
			cnt[i][s[i][j]-'a'+1]++;
		for (int j=26,tot=0; j; j--)
			for (int k=1; k<=cnt[i][j]; k++)
				t[i][++tot]=(char)('a'+j-1);
	}
	int minn=1,mt=2;
	if (cmp1(1,2)) swap(minn,mt);
	for (int i=3; i<=n; i++)
		if (cmp1(minn,i)) {mt=minn; minn=i;}
		else if (cmp1(mt,i)) mt=i;
	memcpy(str,t[minn],sizeof str);
	for (int i=1; i<=n; i++) {
		for (int j=1,tot=0; j<=26; j++)
			while (cnt[i][j]) {
				tmp[++tot]=(char)('a'+j-1);
				cnt[i][j]--;
			}
		if (i==minn) {
			bool flag=false;
			for (int j=1; j<=m; j++)
				if (t[mt][j]!=tmp[j]) {
					flag=t[mt][j]>tmp[j];
					break;
				}
			cout<<flag;
		} else cout<<cmp2();
	} cout<<'\n';
	return 0;
}