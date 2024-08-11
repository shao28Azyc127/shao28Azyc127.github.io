#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
string s;
vector<char>st;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			for(int k = i; k <= j; k++){
				if(st.size()==0){
					st.push_back(s[k]);
					continue;
				}
				if(st.back()==s[k]){
					st.pop_back();
				}else{
					st.push_back(s[k]);
				}
			}
			if(st.size()==0){
				ans++;
				/*for(int k = i; k <= j; k++){
					cout <<s[k];
				}	
				cout <<"\n";*/
			}
			st.clear();
		}
	}
	cout << ans <<"\n";
	return 0;
}