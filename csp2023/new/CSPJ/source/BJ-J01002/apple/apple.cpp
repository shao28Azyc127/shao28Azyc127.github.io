#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
    int n;
    cin>>n;
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	int qd=2,ans=0,np=0;
	while(!q.empty()){
		ans++;
		for(int i=1;i<=n;i+=3){
			if(q.front()==n){
				np=ans;
			}
			q.pop();
			if(i!=1 && q.front()==qd){
				break;
			}
			if(i==1){
				qd=q.front();
			}
			if(q.empty()){
				break;
			}
			q.push(q.front());
			q.pop();
			if(q.front()==qd){
				 break;
			}
			q.push(q.front());
			q.pop();
			if(q.front()==qd){
				 break;
			}
		}
	}
	cout<<ans<<' '<<np;
	return 0;
}
		
