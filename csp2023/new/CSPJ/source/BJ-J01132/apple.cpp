#include<bits/stdc++.h>
using namespace std;
queue<int> q;
queue<int> q2;

int n;

int cont(queue<int> q1){
	int cnt=0;
	while(!q1.empty()){
		cnt++;
		q1.pop();
	}
	
	return cnt;
}


int main(){
	freopen("apple.out","w",stdout);
	freopen("apple.in","r",stdin);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		q.push(i);
	}
	int rd=0,ans=0;
	while(!q.empty()){
		rd++;
		int x=cont(q);
		for(int i=1;i<=x;i++){
			if(i%3==1){
				if(q.front()==n){
					ans=rd;
				}
				q.pop();
			}else{
				q2.push(q.front());
				q.pop();
			}
		}
		while(!q2.empty()){
			q.push(q2.front());
			q2.pop();
		}
	}
	cout<<rd<<" "<<ans;
	
	return 0;
}
