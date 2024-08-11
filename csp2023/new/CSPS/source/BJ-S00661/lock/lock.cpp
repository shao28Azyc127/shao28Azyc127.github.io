
#include<bits/stdc++.h>
using namespace std;
int n;
queue<int> q;
bool ch(int a,int b){
	if(a==b) return 0;
	if(a>b) swap(a,b);
	while(a>0&&b>0){
		int la=a%10; int lb=b%10;
		if(la!=lb){
			int l=la-lb;
			a/=10; b/=10;
			la=a%10;lb=b%10;
			if(a==b){
				return 1;
			}
			else{
				if(l==la-lb&& a/10==b/10 ){
					return 1;
				}
				return 0;
			}
		}
		else{
			a/=10; b/=10;
		}
	}
	return 0;
}
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	//cout<<ch(11111,12211)<<endl;
	
	cin>>n;
	if(n==1){
		int x;for(int i=1;i<=5;i++) cin>>x;
		cout<<81; return 0;
	}
	int x=0;
	for(int i=1;i<=5;i++){
		int y; cin>>y;
		x*=10;
		x+=y;
	}// cout<<x<<endl;
	int sz=0;
	for(int i=10000;i>=1;i/=10){
		int y=x/i%10;
		int v=x-y*i;
//		cout<<endl<<y<<' '<<v<<endl;
		for(int j=1;j<=9;j++){
			//y=(y+j)%10*i;
			q.push(v+((y+j)%10)*i); sz++;
		}
	} 
	for(int i=1000;i>=1;i/=10){
		int y1=x/i%10; int y2=x/(i*10)%10;
		int v=x-y1*i-y2*(i*10);
//		cout<<y1<<' '<<y2<<'!'<<v<<endl;
		for(int j=11;j<=99;j+=11){
			//y=(y+j)%10*i;
			q.push(v+((y1+j)%10)*i+(y2+j)%10*(i*10)); sz++;
		} 
	}
//	while(!q.empty()){
//	cout<<q.front()<<' '; 
//		q.pop();
//	} cout<<sz;
	for(int i=2;i<=n;i++){
		int w=0;
		for(int j=1;j<=5;j++){
			int y; cin>>y;
			w*=10;
			w+=y;
		}//w
		int szz=sz;// cout<<sz<<q.size();
		for(int j=1;j<=szz;j++){
			int p=q.front(); q.pop();
	//		cout<<p<<'|'<<endl;
			if(ch(p,w)==1){
//				cout<<p<<' '<<w<<')'<<endl;
				q.push(p);
			}
			else{
				//cout<<"--";
				sz--;
			}
		}
	}
	cout<<sz;
	return 0;
}
