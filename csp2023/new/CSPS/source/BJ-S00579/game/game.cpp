#include<iostream>
#include<stack>
using namespace std;
const int N=805;
int a[N];
int st[N],ed[N],lst[N];
int ok[N][N],n;
int check(int x,int y){
	if(lst[y]<=x)	return 0;
	stack<int> s;
	int i=x;
	while(i<=y){
		/*cout<<i<<':';
		stack<int> s1=s;
		while(!s1.empty()){
			cout<<s1.top()<<' ';
			s1.pop();
		}
		cout<<endl;*/
		if(s.empty()){
			s.push(a[i]);
			i++;
			continue;
		}
		if(a[i]==s.top()){
			i++;
			if(s.top()>30)	continue;
			int t=s.top();
			s.pop();
			s.push(t+30);
		}
		else{
			while(!s.empty()&&s.top()>30){
				s.pop();
			}
			if(s.empty())	s.push(a[i]);
			else if(a[i]!=s.top())
				s.push(a[i]);
			else	s.top()+=30;
			i++;
		}
	}
	while(!s.empty()&&s.top()>30)	s.pop();
	if(s.empty())	return 1;
	return 0;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'a'+1;
	}
	a[0]=1e9,a[n+1]=1e9;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])	st[i]=st[i-1];
		else if(a[i]==a[i+1])	st[i]=i;
		else	st[i]=0;
	}
	for(int i=n;i>=1;i--){
		if(a[i]==a[i+1])	ed[i]=ed[i+1];
		else if(a[i]==a[i-1])	ed[i]=i;
		else	ed[i]=0;
	}
	for(int i=1;i<=n;i++)
		if(st[i]!=0)	lst[i]=i;
		else			lst[i]=lst[i-1];
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			ans+=check(i,j);
		}
	cout<<ans<<endl;
	return 0;
}