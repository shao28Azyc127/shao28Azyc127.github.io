#include<bits/stdc++.h>
using namespace std;
int T,m,a,b,c;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>m;
	while(T--){
		cin>>a>>b>>c;
		int sj=b*b-4*a*c;
		if(sj<0){
			cout<<"NO";
		}else{
			double x,y;
			x=((-b)+sqrt(sj))/(2*a);
			y=((-b)-sqrt(sj))/(2*a);
			if(x<y) swap(x,y);
			
			cout<<0/(2*a);
		}
	}
	return 0;
}
