#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
char s[200005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n-1;i++)cin>>s[i];
/*	stack<char> t;
	for(int k=0;k<=n-1;k++){
		if(t.empty())t.push(s[k]);
		else if(t.top()==s[k])t.pop();
		else t.push(s[k]);
		stack<char> check;
		while(!t.empty()){
			cout<<t.top();
			check.push(t.top());
			t.pop();
		}
		while(!check.empty()){
			t.push(check.top());
			check.pop();
		}
		cout<<endl;
	}
	if(t.empty())ans++;
	cout<<ans;*/
	for(int i=0;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			stack<char> t;
			for(int k=i;k<=j;k++){
				if(t.empty())t.push(s[k]);
				else if(t.top()==s[k])t.pop();
				else t.push(s[k]);
				stack<char> check;
				/*while(!t.empty()){
					cout<<t.top();
					check.push(t.top());
					t.pop();
				}
				while(!check.empty()){
					t.push(check.top());
					check.pop();
				}
				cout<<endl;*/
			}
			if(t.empty())ans++;
		}
	}
	cout<<ans;
	return 0;
}
