#include<bits/stdc++.h>
using namespace std;
int T,M;
int main(){
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	cin>>T>>M;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		int delta=b*b-4*a*c;
		if(delta<0)cout<<"NO"<<endl;
		else{
			if(c==0&&b==0)cout<<0<<endl;
			else if(c==0)cout<<-b/__gcd(abs(b),a)<<"/"<<a/__gcd(abs(b),a)<<endl;
			else if(b==0){
				if(-c%a==0){
					if(sqrt(-c/a)*sqrt(-c/a)==-c/a)cout<<sqrt(-c/a)<<endl;
				}
			}
		} 
	}
	return 0;
}
