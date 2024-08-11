#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
int n;
char s[2000005];
stack<char> t;
long long ans=-1;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	//cout<<n<<endl;
	
	
	//t.push(s[0]);
	for(int i=0;i<n;i++){
		cin>>s[i];
		/*while*/if(!t.empty()){
			if(s[i]==t.top()){
				t.pop();
				ans++;
			}
			else{
				t.push(s[i]);
			}
		}
		else {
			ans++;
			t.push(s[i]);
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
