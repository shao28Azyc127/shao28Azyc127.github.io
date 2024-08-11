#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
stack<char> s;
long long cnt = 0ll;
int n;
const int MAXX = 2e6+5;
char c[MAXX],tmp[MAXX];
bool check(int len){
	while(!s.empty())s.pop();
	//for(int i=0;i<len;i++)cout<<tmp[i]<<" ";
	//cout<<endl;
	s.push(tmp[0]);
	//cout<<len<<endl;
	for(int i=1;i<len;i++){
		if(!s.empty() && s.top()==tmp[i]){
			s.pop();
		}else s.push(tmp[i]);
	}
	if(s.empty())return 1;
	return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d",&n);
	scanf("%s",c);
	for(int i=0;i<n;i++){
		//cout<<i<<endl;
		for(int j=2;i+j<=n;j+=2){
			for(int k=i;k<i+j;k++)tmp[k-i] = c[k];
			if(check(j))cnt++;
		}
	}
	printf("%lld",cnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
