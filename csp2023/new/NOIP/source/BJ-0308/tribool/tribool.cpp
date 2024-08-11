#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m;
struct qu{
	char c;ll a,b;
}q[N];
char temp[N];
char a[N];bool flag=0;ll ans;
bool check(){
	for(int i=1;i<=n;i++)temp[i]=a[i];
	for(int i=1;i<=m;i++){
		if(q[i].c=='T'){temp[q[i].a]='T';}
		else if(q[i].c=='F'){temp[q[i].a]='F';}
		else if(q[i].c=='U'){temp[q[i].a]='U';}
		else if(q[i].c=='+'){temp[q[i].a]=temp[q[i].b];}
		else if(q[i].c=='-'){
			if(temp[q[i].b]=='U'){temp[q[i].a]='U';}
			else if(temp[q[i].b]=='F'){temp[q[i].a]='T';}
			else if(temp[q[i].b]=='T'){temp[q[i].a]='F';}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=temp[i])return 0;
	}
	return 1;
}
void dfs(ll pos,ll sum){
	if(flag)return;
	if(pos==n+1){
		if(check()){
			ans=min(ans,sum);
			if(sum==0)flag=1;
		}
		return;
	}
	a[pos]='T';
	dfs(pos+1,sum);
	a[pos]='F';
	dfs(pos+1,sum);
	a[pos]='U';
	dfs(pos+1,sum+1);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;int p=0;
	while(T--){
		cin>>n>>m;p++;
		for(int i=1;i<=m;i++){
			cin>>q[i].c;
			if(q[i].c=='+'||q[i].c=='-'){
				cin>>q[i].a>>q[i].b;
			}
			else{
				cin>>q[i].a;
			}
		}
		if(c==1||c==2){
			ans=1e7;flag=0;
			dfs(1,0);cout<<ans<<endl;
		}
		else if(c==3||c==4){
			for(int i=1;i<=n;i++)a[i]='T';
			for(int i=1;i<=m;i++){
				if(q[i].c=='T'){a[q[i].a]='T';}
				else if(q[i].c=='F'){a[q[i].a]='F';}
				else if(q[i].c=='U'){a[q[i].a]='U';}
			}
			ll cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]=='U')cnt++;
			}
			cout<<cnt<<endl;
		}
		else if(c==5||c==6){
			for(int i=1;i<=n;i++){
				a[i]='T';
			}
			for(int i=1;i<=m;i++){
				if(q[i].c=='+'){
					a[q[i].a]=a[q[i].b];
				}
				if(q[i].c=='U'){a[q[i].a]='U';}
			}
			for(int i=1;i<=m;i++){
				if(q[i].c=='+'&&a[q[i].b]=='U'){
					a[q[i].a]=a[q[i].b];
				}
			}
			ll cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]=='U')cnt++;
			}
			cout<<cnt<<endl;
		}
		else if(c==7||c==8){
			cout<<0<<endl;
		}
	}
	return 0;
}
//T T U F U F U T F F
