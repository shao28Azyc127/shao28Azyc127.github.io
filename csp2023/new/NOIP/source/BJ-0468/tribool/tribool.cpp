#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
#define t 998244353
#define f 1000000007
#define u 19260817
using namespace std;

int a[100008];
int ans[100008];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)a[i]=i;
		if(c==5||c==6){
			for(int i=1;i<=n;i++)ans[i]=T;
		}
		for(int i=1;i<=m;i++){
			string op;cin>>op;
			if(op=="+"){
				int x,y;
				cin>>x>>y;
				a[x]=y;
				ans[x]=ans[y];
			}
			else if(op=="-"){
				int x,y;
				cin>>x>>y;
				a[x]=-y;
				ans[x]=-ans[y];
			}
			else{
				int x;
				cin>>x;
				if(op=="T"){
					ans[x]=t;
					a[x]=x;
				}
				if(op=="F"){
					ans[x]=f;a[x]=x;
				}
				if(op=="U"){
					ans[x]=u;a[x]=x;
				}
			}
		//	cout<<"ok"<<endl;
		}
		queue<int> q;
		for(int i=1;i<=n;i++){
			q.push(i);
		}
		int cnt=0;
		while(!q.empty()){
			//cout<<"ok!!!!\n";
			//for(int i=1;i<=n;i++){
			//	cout<<i<<": "<<a[i]<<" "<<ans[i]<<endl;
			//}
			//int zz;
			//cin>>zz;
			int x=q.front();q.pop();
			if(abs(ans[x])==abs(t))continue;
			else if(abs(ans[x])==abs(f))continue;
			else if(abs(ans[x])==abs(u)){
				cnt++;
				continue;
			}
			else if(a[x]==x){
				ans[x]=t;
			}
			else if(a[x]==-x){
				ans[x]=u;cnt++;
			}
			else{
				if(ans[abs(a[x])]==0){
					if(a[x]<0){
						a[x]=-a[abs(a[x])];
					}
					else{
						a[x]=a[abs(a[x])];
					}
					q.push(x);
					continue;
				}
				if(a[x]<0){
					ans[x]=-ans[abs(a[x])];
					if(abs(ans[x])==abs(u)){
						cnt++;
					}
				}
				else {
					ans[x]=ans[a[x]];
					if(abs(ans[x])==abs(u)){
						cnt++;
					}
				}
			}
			
			
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
