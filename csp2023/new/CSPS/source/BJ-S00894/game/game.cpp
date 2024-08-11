#include<bits/stdc++.h>
using namespace std;
string s,z;
char u[2000010];
int ans1,n,ans2;
bool flag;
int w[27];
int vis[2000010];
bool check(string a){
	for(int i = 0; i < a.size(); i++){
		w[a[i]]++;
		u[i] = a[i];
	}
	for(int i = 1; i <= 27; i++){
		if(w[i]%2 == 1) return 0; 
	}
}
int f(string e){
	int ans = 0;
	for(int i = 0;i < e.size();i++){
		for(int j = i + 1; j < e.size();j++){
			for(int k = i; k <= j; k++){
				z += e[k];
			}
			if(check(z)) ans++;
		}
	}
	return ans;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin >> n;
	cin >> s;
	cout << f(s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
