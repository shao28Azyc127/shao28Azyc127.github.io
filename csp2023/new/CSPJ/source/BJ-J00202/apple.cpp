#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	int n,d=0,day=0;
	cin>>n;
	for(int i=1;i<=n;i++) q.push(i);
	while(!q.empty()){
		day++;
		int a=q.size();
		for(int i=1;i<=a;i+=3){
			if(q.front()==n) d=day;
			q.pop();
			if(!q.empty()&&i+1<=a){
				q.push(q.front());
				q.pop();
			}if(!q.empty()&&i+2<=a){
				q.push(q.front());
				q.pop();
			}
		}
	}cout<<day<<" "<<d;
	return 0;
}
