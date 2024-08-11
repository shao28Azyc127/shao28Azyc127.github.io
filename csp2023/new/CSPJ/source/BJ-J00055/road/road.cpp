#include<bits/stdc++.h>
using namespace std;
int n,u[100005],s[100005],d,rl[100005],ss[100005];
long long you,qian,j=1;
stack<int> st;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&d);
	for(int i=1;i<n;i++){
		scanf("%d",&u[i]);
		ss[i+1]=ss[i]+u[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	for(int i=1;i<=n;i++){
		while(!st.empty()){
			if(s[i]<s[st.top()]){
				rl[st.top()]=i;
				st.pop();
			}else{
				break;
			}
		}
		st.push(i);
	}
	while(j<n){
		long long xx,yy;
		if(rl[j]==0){
			xx=ss[n]-ss[j]-you;
			yy=ceil(xx/1.0/d);
			qian+=yy*s[j];
			j=n;
		}else{
			xx=ss[rl[j]]-ss[j]-you;
			yy=ceil(xx/1.0/d);
			qian+=yy*s[j];
			you=yy*d-xx;
			j=rl[j];
		}
	}cout<<qian<<endl;
	return 0;
}
