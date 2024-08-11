#include<iostream>
#include<cmath>
using namespace std;

double judge(int a,int b,int c){
	return b*b-4*a*c;
}
double jie(int a,int b,int c){
	return max((-b+sqrt(judge(a,b,c)))/(2*a),(-b-sqrt(judge(a,b,c)))/(2*a));
}
double iszheng(double x){
	if(x==(int)x) return true;
	else return false;
}

int main(){
	ios::sync_with_stdio(0);
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	int t,m,a,b,c;
	cin>>t>>m;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		if(judge(a,b,c)<0){
			cout<<"NO\n";
			continue;
		}
		if(iszheng(sqrt(judge(a,b,c)))){
			double x=jie(a,b,c);
			int y=1;
			while(!iszheng(x)){
				x*=10;
				y*=10;
			}
			int t=x;
			for(int i=2;i<=min(abs(t),y);i++){
				while((int)x%i==0 && y%i==0){
					x/=i;
					y/=i;
				}
			}
			if(y==1) cout<<x<<"\n";
			else cout<<x<<"/"<<y<<"\n";
		}
		else{
			int cnt=1;
			int x=judge(a,b,c);
			for(int i=2;i<x;i++){
				int cur=0;
				while(x%i==0){
					x/=i;
					cur++;
				}
				cnt=cnt*(pow(i,cur/2));
				if(cur%2==1) x*=i;
			}
			if(cnt%(2*a)==0){
				if(cnt/(2*a)==1) cout<<"sqrt("<<x<<")\n";
				else cout<<cnt/2/a<<"*sqrt("<<x<<")\n";
			}
		}
	}
	return 0;
}	
