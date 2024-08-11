#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
int n;
char s[2000005];
stack<char> t,ts;
long long ans=0,ans2=0, cnt=0;

bool flag=true;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	//cout<<n<<endl;
	
	
	int stat;
	for(int i=0;i<n;i++){
		cin>>s[i];
		if(!t.empty()){
			if(s[i]==t.top()){
				t.pop();
				if(flag){
					flag=false;
					ts.push(s[i]);
					stat=i;
				}
				ans++;
			}
			else{
				t.push(s[i]);
			}
		}
		else {
			if(i!=0) cnt++;
			t.push(s[i]);
		}
	}
	if(t.empty()){
		cnt++;
	}
	ans+=(cnt*(cnt-1)/2);
	
	//cout<<ans<<endl;
	//cout<<endl;
	
	cnt=0;
	for(int i=stat+1;i<n;i++){
		if(!ts.empty()){
			if(s[i]==ts.top()){
				ts.pop();
				ans2++;
			}
			else{
				ts.push(s[i]);
			}
		}
		else {
			ts.push(s[i]);
		}
	}
	//cout<<cnt<<endl;
	if(ts.empty()){
		cnt++;
	}
	ans2+=(cnt*(cnt-1)/2);
	
	//cout<<cnt<<endl;
	
	cout<<ans2+ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
