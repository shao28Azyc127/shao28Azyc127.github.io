#include<bits/stdc++.h>
using namespace std;
string str1;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,ans=0;
	cin>>n;
	cin>>str1;
	for(int i=n;i>=1;i--)
		str1[i] = str1[i-1];
	for(int i=1;i<=n;i++){
		for(int j=2;j+i-1<=n;j+=2){
			stack<char> st;
			for(int k=i;k<=j+i-1;k++){
				char f;
				if(!st.empty()) 
					f = st.top();
				st.push(str1[k]);
				if(k!=i){
					if(f==str1[k]){
						st.pop();st.pop();
					}
				}
			}
			if(st.empty()) ans++;
		}
	}
	cout<<ans;
	return 0;
}
