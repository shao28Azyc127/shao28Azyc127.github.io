#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 3005;
const int M = 3005;

string s[N],a[N],b[N],c[N];
int buc[60];
int n,m;

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		s[i] = "_" + s[i];
		for(int j = 1;j <= m;j++){
			buc[s[i][j]-'a']++;
		}
		a[i] = "_";
		for(int j = 0;j < 26;j++){
			while(buc[j] != 0){
				a[i] += (char)(j + 'a');
				buc[j]--;
			}
		}
		for(int j = 1;j <= m;j++){
			buc[s[i][j]-'a']++;
		}
		b[i] = "_";
		for(int j = 25;j >= 0;j--){
			while(buc[j] != 0){
				b[i] += (char)(j + 'a');
				buc[j]--;
			}
		}
		c[i] = b[i];
		//~ cout << a[i] << " " << b[i] << "\n";
	}
	sort(c+1,c+1+n);
	for(int i = 1;i <= n;i++){
		int idx = upper_bound(c+1,c+1+n,a[i])-c;
		if((idx == 1) || (idx == 2 && c[1] == b[i])){
			cout << 1;
		} else {
			cout << 0;
		}
	}
	cout << "\n";
	return 0;
}
