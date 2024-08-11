#include<iostream>
using namespace std;
int qqq(int a){
	for(int i=1;i<=a;i++){
		if(i*i==a) return i;
	}
}
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	
	int t,m,a,b,c;
	for(int i=1;i<t;i++){
		cin>>a>>b>>c;
		if(b*b-4*a*c<0) cout<<"NO";
		else {
			int s1=(-b+qqq(b*b-4*a*c))/(2*a);
			int s2=(-b-qqq(b*b-4*a*c))/(2*a);
			if(b*b-4*a*c==0) cout<<s1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
