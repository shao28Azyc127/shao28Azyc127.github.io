#include<bits/stdc++.h>
using namespace std;
int c,t;
char gc;
int bucket[100005];
int n,m,ans,cnt,one,two,put;
int dap[15];
int test[15];
struct what{
	char haha;
	int one,two;
}todo[15];
void dfs(int x){
	if(x==n){
		for(int i=1;i<=n;i++){
			test[i]=dap[i];
		}
		for(int i=1;i<=m;i++){
			if(todo[i].haha=='+'){
				test[todo[i].one]=test[todo[i].two];
			}
			if(todo[i].haha=='-'){
				if(todo[i].one==todo[i].two){
					test[todo[i].one]=3;
				}
				if(test[todo[i].two]==1){
					test[todo[i].one]=2;
				}
				if(test[todo[i].two]==2){
					test[todo[i].one]=1;
				}
				if(test[todo[i].two]==3){
					test[todo[i].one]=3;
				}
			}
			if(todo[i].haha=='T'){
				test[todo[i].one]=1;
			}
			if(todo[i].haha=='F'){
				test[todo[i].one]=2;
			}
			if(todo[i].haha=='U'){
				test[todo[i].one]=3;
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(test[i]!=dap[i]){
				flag=false;
				break;
			}
		}
		cnt=0;
		if(flag==true){
			for(int i=1;i<=n;i++){
				if(dap[i]==3){
					cnt++;
				}
			}
			ans=min(ans,cnt);
		}
		return;
	}
	for(int i=1;i<=3;i++){
		dap[x+1]=i;
		dfs(x+1);
	}
	return;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==1 || c==2){
		for(int happy=1;happy<=t;happy++){
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				cin>>todo[i].haha;
				if(todo[i].haha=='-' || todo[i].haha=='+'){
					cin>>todo[i].one>>todo[i].two;
				}else{
					cin>>todo[i].one;
				}
			}
			memset(dap,0,sizeof(dap));
			ans=100;
			dfs(0);
			cout<<ans<<endl;
		}
	}
	if(c==3 || c==4){
		for(int happy=1;happy<=t;happy++){
			cin>>n>>m;
			memset(bucket,0,sizeof(bucket));
			for(int i=1;i<=m;i++){
				cin>>gc>>cnt;
				if(gc=='T'){
					bucket[cnt]=1;
				}
				if(gc=='F'){
					bucket[cnt]=2;
				}
				if(gc=='U'){
					bucket[cnt]=3;
				}
			}
			ans=0;
			for(int i=1;i<=n;i++){
				if(bucket[i]==3){
					ans++;
				}
			}
			cout<<ans;
		}
	}
/*	if(c==5 || c==6){
		for(int happy=1;happy<=t;happy++){
			cin>>n>>m;
			memset(bucket,0,sizeof(bucket));
			for(int i=1;i<=n;i++){
				bucket[i]=i;
			}
			for(int i=1;i<=m;i++){
				cin>>gc;
				if(gc=='+'){
					cin>>one>>two;
					put=bucket[two]
					for(int i=1;i<=n;i++){
						if(
					}
				}
			}
		}
	}*/
	return 0;
}