#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdout);
	freopen("apple.out","w",stdout);
	int n,cnt=0,cntn;
	cin>>n;
	queue<int> q;
	for(int i=1;i<=n;i++) q.push(i);
//	cout<<q.front()<<endl;
	while(!q.empty()){
		cnt++;
		int lq=q.size();
//		cout<<q.front()<<" ";
		for(int i=1;i<=lq;i++){
			if(i%3==1){
				if(q.front()==n) cntn=cnt;
//				cout<<q.front()<<" ";
				q.pop();
			}else{
				int a=q.front();
				q.pop();q.push(a);
			}
		}
//		cout<<endl;
	}
	cout<<cnt<<" "<<cntn;
	return 0;
}/**/